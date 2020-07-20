#include <libgba-sprite-engine/scene.h>

class MiniGame3 : public Scene {
private:
    std::unique_ptr<Sprite> karakter;
    std::unique_ptr<Background> bg;
    int score3;
    int pressed=0, level=0;

public:
    MiniGame3(const std::shared_ptr<GBAEngine> &engine);

    std::vector<Sprite *> sprites() override;

    std::vector<Background *> backgrounds() override;

    void load() override;

    void tick(u16 keys) override;
};