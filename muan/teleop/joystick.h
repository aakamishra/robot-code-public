#ifndef MUAN_TELEOP_JOYSTICK_H_
#define MUAN_TELEOP_JOYSTICK_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "WPILib.h"
#include "muan/teleop/button.h"
#include "muan/teleop/queue_types.h"

namespace muan {

namespace teleop {

class Joystick {
 public:
  explicit Joystick(int32_t port);
  Joystick(int32_t port, JoystickStatusQueue* queue);

  void Update();

  muan::teleop::Button* GetButton(uint32_t button);
  muan::teleop::Button* GetPov(uint32_t pov, Pov position);
  muan::teleop::Button* GetAxis(uint32_t button);

  ::Joystick* wpilib_joystick();

 private:
  void LogButtons();

  JoystickStatusQueue* queue_;

  std::vector<std::unique_ptr<Button>> buttons_;
  std::vector<std::unique_ptr<Button>> axis_;
  std::vector<std::unique_ptr<Button>> pov_;
  ::Joystick wpilib_joystick_;
};

}  // namespace teleop

}  // namespace muan

#endif  // MUAN_TELEOP_JOYSTICK_H_
