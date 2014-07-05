#pragma once
#include "RenderContext.h"
#include "enums.h"

#define PAN_AMOUNT 5
class Camera
{
public:
  Camera();
  ~Camera();

  POINT translateToView(POINT pt);
  int getXOffset() { return m_xOffset; }
  int getYOffset() { return m_yOffset; }
  POINT getOffset() { return { m_xOffset, m_yOffset}; }

  void pan(PanDirection dir);

private:
  int m_xOffset = 0;
  int m_yOffset = 0;

};