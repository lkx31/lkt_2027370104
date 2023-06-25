import threading
from predict import Predict
from socket_server import Socket_server, onProcess
import torch
import torchvision.transforms as transforms
from model_v3 import mobilenet_v3_small
import os

weights_path = "wuyijun.pth"
class_json_path = "./class_indices.json"
assert os.path.exists(weights_path), "weights path does not exist..."
assert os.path.exists(class_json_path), "class json path does not exist..."

# select device
device = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")
# create model
model = mobilenet_v3_small(num_classes=4).to(device)
# load model weights
model.load_state_dict(torch.load(weights_path, map_location=device))

my_transforms = transforms.Compose([transforms.Resize(255),
                                    transforms.CenterCrop(224),
                                    transforms.ToTensor(),
                                    transforms.Normalize(
                                        [0.485, 0.456, 0.406],
                                        [0.229, 0.224, 0.225])])


def start_server():

    predictor = Predict(device, class_json_path, model, my_transforms)
    onListener = onProcess(predictor)
    server = Socket_server(onListener=onListener)
    server.start()


def start_server_in_thread():
    thread = threading.Thread(target=start_server)
    thread.start()
    thread.join()

if __name__ == "__main__":
    start_server_in_thread()