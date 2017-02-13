#include "c2017/vision/coprocessor/sender.h"

namespace c2017 {
namespace vision {

void RunSender(char* target_ip) {
  aos::vision::TXUdpSocket sender_socket(target_ip, 1678);
  auto queue_reader = vision_queue.MakeReader();
  char buffer[1024];
  while (true) {
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    auto message = queue_reader.ReadLastMessage();
    if (message) {
      message.value()->SerializeToArray(buffer, 1024);
    }
    sender_socket.Send(buffer, 1024);
  }
}

c2017::vision::VisionInputQueue vision_queue;

}  // namespace vision
}  // namespace c2017
