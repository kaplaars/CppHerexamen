
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
    return {};
}

std::vector<Background *> StartScene::backgrounds() {
    return {
            bg.get()
    };
}

void StartScene::load() {
    //engine.get()->disableText();
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(pokemapPal, sizeof(pokemapPal)));

    bg = std::unique_ptr<Background>(new Background(0, pokemapTiles, sizeof(pokemapTiles), pokemapMap, sizeof(pokemapMap)));
    bg.get()->useMapScreenBlock(24);

    SpriteBuilder<Sprite> builder;
/*
    animation = builder
            .withData(karakterTiles, sizeof(karakterTiles))
            .withSize(SIZE_32_32)
            .withAnimated(3, 3)
            .withLocation(100, 50)
            .buildPtr();

    TextStream::instance().setText("PRESS START", 3, 8);
*/
    engine->getTimer()->start();

    //engine->enqueueMusic(zelda_music_16K_mono, zelda_music_16K_mono_bytes);
}

void StartScene::tick(u16 keys) {
    //TextStream::instance().setText(engine->getTimer()->to_string(), 18, 1);
/*
    if(pressingAorB && !((keys & KEY_A) || (keys & KEY_B))) {
        engine->getTimer()->toggle();
        pressingAorB = false;
    }

    if(keys & KEY_START) {
        if(!engine->isTransitioning()) {
            //engine->enqueueSound(zelda_secret_16K_mono, zelda_secret_16K_mono_bytes);

            TextStream::instance() << "entered: starting next scene";

            //engine->transitionIntoScene(new FlyingStuffScene(engine), new FadeOutScene(2));
        }
    } else if(keys & KEY_LEFT) {
        animation->flipHorizontally(true);
    } else if(keys & KEY_RIGHT) {
        animation->flipHorizontally(false);
    } else if(keys & KEY_UP) {
        animation->flipVertically(true);
    } else if(keys & KEY_DOWN) {
        animation->flipVertically(false);
    } else if((keys & KEY_A) || (keys & KEY_B)) {
        pressingAorB = true;
    }*/
}
