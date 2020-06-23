

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

#include "StartScene.h"
#include "CollorPallet.h"
#include "karakter.h"
//#include "sample_sound.h"
#include "background.h"

StartScene::StartScene(const std::shared_ptr<GBAEngine> &engine) : Scene(engine) {}

std::vector<Sprite *> StartScene::sprites() {
    return {  animation.get()};
}

std::vector<Background *> StartScene::backgrounds() {
    return {
            bg.get()
    };
}

void StartScene::load() {
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(gbmapPal, sizeof(gbmapPal)));
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));

    bg = std::unique_ptr<Background>(new Background(0, gbmapTiles, sizeof(gbmapTiles), gbmapMap, sizeof(gbmapMap)));
    bg.get()->useMapScreenBlock(24);

    SpriteBuilder<Sprite> builder;

    animation = builder
            .withData(karakterTiles, sizeof(karakterTiles))
            .withSize(SIZE_32_32)
            .withAnimated(3, 10)
            .withLocation(100, 100)
            .buildPtr();
/*
    TextStream::instance().setText("PRESS START", 3, 8);
*/
    engine->getTimer()->start();

    //engine->enqueueMusic(zelda_music_16K_mono, zelda_music_16K_mono_bytes);
}

void StartScene::tick(u16 keys) {
    //TextStream::instance().setText(engine->getTimer()->to_string(), 18, 1);

    if(keys & KEY_LEFT) {
        animation->setVelocity(-2, 0);
    } else if(keys & KEY_RIGHT) {
        animation->setVelocity(2, 0);
    } else if(keys & KEY_UP) {
        animation->setVelocity(0, -2);
    } else if(keys & KEY_DOWN) {
        animation->setVelocity(0, 2);
    } else{
        animation->setVelocity(0, 0);
    }
}
