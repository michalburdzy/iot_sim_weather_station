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
public:
  LightDetector(int leftTopPin, int rightTopPin, int rightBottomPin, int leftBottomPin);
  LightDetectionResult measure();
  LightDetectionMovementResult plotMovement(LightDetectionResult data);

private:
  int ltPin;
  int rtPin;
  int rbPin;
  int lbPin;
};