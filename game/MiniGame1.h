class MiniGame1 : public Scene {
private:
    std::unique_ptr<Background> bg;
    std::unique_ptr<Sprite> RPC;
    int selection, randnum;

public:
    MiniGame1(const std::shared_ptr<GBAEngine> &engine);

    std::vector<Sprite *> sprites() override;

    std::vector<Background *> backgrounds() override;

    void load() override;

    void tick(u16 keys) override;
};