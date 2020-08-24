#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>

#include "MiniGame3.h"
#include "GameRoom3.h"

#include "StartScene.h"
#include "CollorPallet.h"
#include "karakter.h"

MiniGame3::MiniGame3(const std::shared_ptr<GBAEngine> &engine) : Scene(engine) {}

std::vector<Sprite *> MiniGame3::sprites() {
    return {karakter.get()};
}

std::vector<Background *> MiniGame3::backgrounds() {
    return {
            bg.get()
    };
}

void MiniGame3::tick(u16 keys) {
    //ga terug naar main map
    if(keys & KEY_L) {
        engine->setScene(new StartScene(engine));
        StartScene::totaalscore = StartScene::totaalscore + score3;
    }

    if(engine->getTimer()->getMsecs()>900){
        pressed = 0;
    }

    TextStream::instance().setText(engine->getTimer()->to_string(), 18, 1);
    TextStream::instance().setText("score: " + std::to_string(score3), 2, 1);

    if(engine->getTimer()->getSecs() == 5){
        TextStream::instance().setText("pres A", 3, 1);
        level = 1;
    }
    if(level == 1 && keys & KEY_A && pressed == 0){
        score3 = score3+(999-engine->getTimer()->getMsecs());
        pressed = 1;
    }

    if(engine->getTimer()->getSecs() == 6){
        TextStream::instance().setText("pres B", 3, 1);
        level = 2;
    }
    if(level == 2 && keys & KEY_B && pressed == 0){
        score3 = score3+(999-engine->getTimer()->getMsecs());
        pressed = 1;
    }

    if(engine->getTimer()->getSecs() == 7){
        TextStream::instance().setText("pres A", 3, 1);
        level = 3;
    }
    if(level == 3 && keys & KEY_A && pressed == 0){
        score3 = score3+(999-engine->getTimer()->getMsecs());
        pressed = 1;
    }

    if(engine->getTimer()->getSecs() == 8){
        TextStream::instance().setText("pres B", 3, 1);
        level = 4;
    }
    if(level == 4 && keys & KEY_B && pressed == 0){
        score3 = score3+(999-engine->getTimer()->getMsecs());
        pressed = 1;
    }

    if(engine->getTimer()->getSecs() == 9){
        TextStream::instance().setText("pres UP", 3, 1);
        level = 5;
    }
    if(level == 5 && keys & KEY_UP && pressed == 0){
        score3 = score3+(999-engine->getTimer()->getMsecs());
        pressed = 1;
    }

    if(engine->getTimer()->getSecs() == 10){
        TextStream::instance().setText("pres DOWN", 3, 1);
        level = 6;
    }

    if(level == 6 && keys & KEY_DOWN && pressed == 0){
        score3 = score3+(999-engine->getTimer()->getMsecs());
        pressed = 1;
    }

    if(engine->getTimer()->getSecs() == 12){
        TextStream::instance().setText("well done cowboy", 3, 1);
        level = 7;
    }

    if(keys & KEY_B) {
        karakter->setVelocity(1, 0);
    } else if(keys & KEY_A) {
        karakter->setVelocity(-1, 0);
    } else if(keys & KEY_UP) {
        karakter->setVelocity(0, -1);
    } else if(keys & KEY_DOWN) {
        karakter->setVelocity(0, 1);
    } else{
        karakter->setVelocity(0, 0);
    }
}

void MiniGame3::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(huisje_3Pal, sizeof(huisje_3Pal)));

    engine.get()->enableText();

    level = 0;
    score3 = 0;

    bg = std::unique_ptr<Background>(new Background(1, huisje_3Tiles, sizeof(huisje_3Tiles), huisje_3Map, sizeof(huisje_3Map)));
    bg.get()->useMapScreenBlock(16);

    engine->getTimer()->reset();
    engine->getTimer()->start();

    SpriteBuilder<Sprite> builder;

    karakter = builder
            .withData(karakterTiles, sizeof(karakterTiles))
            .withSize(SIZE_32_32)
            .withLocation(120, 70)
            .withAnimated(3, 20)
            .withinBounds()
            .buildPtr();

}