#include <iostream>
#include <optional>

struct ObjectRange {
    short iXStart;
    short iXEnd;
    short iYStart;
    short iYEnd;
    int iQpOffset;

    ObjectRange() : iXStart(0), iXEnd(0), iYStart(0), iYEnd(0), iQpOffset(0) {}

    ObjectRange(ObjectRange &&) = delete;
    ObjectRange &operator=(const ObjectRange &) = default;
    ObjectRange &operator=(ObjectRange &&) = delete;
    ObjectRange(short xStart, short xEnd, short yStart, short yEnd,
                int qpOffset)
        : iXStart(xStart), iXEnd(xEnd), iYStart(yStart), iYEnd(yEnd),
          iQpOffset(qpOffset) {}

    ObjectRange(const ObjectRange &other) {
        iXStart = other.iXStart;
        iXEnd = other.iXEnd;
        iYStart = other.iYStart;
        iYEnd = other.iYEnd;
        iQpOffset = other.iQpOffset;
    }

    void show() {
        std::cout << "iXStart=" << iXStart << ", iXEnd=" << iXEnd
                  << ", iYStart=" << iYStart << ", iYEnd=" << iYEnd
                  << ", iQpOffset=" << iQpOffset;
    }
};

class VideoTrackSource {
  private:
    const std::optional<ObjectRange> mObjectRange;

  public:
    VideoTrackSource(const std::optional<ObjectRange> &objectRange)
        : mObjectRange(objectRange) {}
    ObjectRange getObjectRange() const { return mObjectRange.value(); }
};

int main(int argc, char *argv[]) {
    auto objectRange = std::make_optional<ObjectRange>(0, 0, 0, 0, 0);
    auto pVideoTrackSource = new VideoTrackSource(objectRange);
    pVideoTrackSource->getObjectRange().show();
    return 0;
}
