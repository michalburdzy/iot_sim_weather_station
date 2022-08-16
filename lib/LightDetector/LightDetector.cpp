#include <Arduino.h>

struct LightDetectionResult
{
  int leftTop;
  int rightTop;
  int rightBottom;
  int leftBottom;
};

struct LightDetectionMovementResult
{
  bool shouldMoveLeft;
  bool shouldMoveRight;
  bool shouldMoveTop;
  bool shouldMoveBottom;
};

class LightDetector
{
  private:
    int ltPin;
    int rtPin;
    int rbPin;
    int lbPin;

public:
  LightDetector(int leftTopPin, int rightTopPin, int rightBottomPin, int leftBottomPin)
  {
    ltPin = leftTopPin;
    rtPin = rightTopPin;
    rbPin = rightBottomPin;
    lbPin = leftBottomPin;

    pinMode(ltPin, INPUT);
    pinMode(rtPin, INPUT);
    pinMode(rbPin, INPUT);
    pinMode(lbPin, INPUT);
  }

  LightDetectionResult measure()
  {
    LightDetectionResult result;
    result.leftTop = digitalRead(ltPin);
    result.rightTop = digitalRead(rtPin);
    result.rightBottom = digitalRead(rbPin);
    result.leftBottom = digitalRead(lbPin);

    return result;
  }

  LightDetectionMovementResult plotMovement(LightDetectionResult data)
  {
    bool shouldMoveLeft = data.leftTop > data.rightTop && data.leftBottom > data.rightBottom;
    bool shouldMoveRight = data.leftTop < data.rightTop && data.leftBottom < data.rightBottom;
    bool shouldMoveTop = data.leftTop > data.leftBottom && data.rightTop > data.rightBottom;
    bool shouldMoveBottom = data.leftTop < data.leftBottom && data.rightTop < data.rightBottom;

    LightDetectionMovementResult result;
    result.shouldMoveLeft = shouldMoveLeft;
    result.shouldMoveRight = shouldMoveRight;
    result.shouldMoveTop = shouldMoveTop;
    result.shouldMoveBottom = shouldMoveBottom;

    return result;
  }
};