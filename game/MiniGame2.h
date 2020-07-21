class MiniGame2 : public Scene {
private:
    std::unique_ptr<Background> bg;
    int story = 0, level = 0, score2, pressed = 0;

public:
    MiniGame2(const std::shared_ptr<GBAEngine> &engine);

    std::vector<Sprite *> sprites() override;

    std::vector<Background *> backgrounds() override;

    void load() override;

    void tick(u16 keys) override;
};