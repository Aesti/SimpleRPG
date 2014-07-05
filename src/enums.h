#pragma once

enum UpdateMessage {
  MOVE_PLAYER = 0
};

enum UpdateData {
  MOVE_UP = 0,
  MOVE_DOWN,
  MOVE_LEFT,
  MOVE_RIGHT
};

enum PanDirection {
  PAN_UP = 0,
  PAN_DOWN, 
  PAN_LEFT,
  PAN_RIGHT
};