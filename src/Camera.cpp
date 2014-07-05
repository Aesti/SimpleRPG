#include "Camera.h"

Camera::Camera() { }

Camera::~Camera() {}

POINT Camera::translateToView(POINT pt) {
  return { pt.x - m_xOffset, pt.y - m_yOffset};
}

void Camera::pan(PanDirection direction) {
  switch(direction) {
    case PAN_UP:
      m_yOffset -= PAN_AMOUNT;
      break;
    case PAN_DOWN:
      m_yOffset += PAN_AMOUNT;
      break;
    case PAN_LEFT:
      m_xOffset -= PAN_AMOUNT;
      break;
    case PAN_RIGHT:
      m_xOffset += PAN_AMOUNT;
      break;
    default:
      break;
  }
}