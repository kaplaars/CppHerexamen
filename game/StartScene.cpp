#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include <libgba-sprite-engine/background/text_stream.h>

#include "StartScene.h"
#include "MiniGame1.h"
#include "MiniGame2.h"
#include "MiniGame3.h"

#include "CollorPallet.h"
#include "karakter.h"

#include "sample_sound.h"
#include "background.h"

StartScene::StartScene(const std::shared_ptr<GBAEngine> &engine) : Scene(engine) {}

std::vector<Sprite *> StartScene::sprites() {
    return {animation.get()};
}

std::vector<Background *> StartScene::backgrounds() {
    return {
            bg.get()
    };
}

void StartScene::load() {
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(gbmapPal, sizeof(gbmapPal)));
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));

    engine.get()->enableText();

    bg = std::unique_ptr<Background>(new Background(0, gbmapTiles, sizeof(gbmapTiles), gbmapMap, sizeof(gbmapMap)));
    bg.get()->useMapScreenBlock(24);

    SpriteBuilder<Sprite> builder;

    animation = builder
            .withData(karakterTiles, sizeof(karakterTiles))
            .withSize(SIZE_32_32)
            .withAnimated(3, 20)
            .withLocation(100, 100)
            .withinBounds()
            .buildPtr();

    engine->getTimer()->start();

    engine->enqueueMusic(zelda_music_16K_mono, zelda_music_16K_mono_bytes);
}

void StartScene::tick(u16 keys) {
    //TextStream::instance().setText(std::string("Score: ") + std::to_string(MiniGame1::getScore()), 7, 10);

    //manneke bewegen
    if(keys & KEY_LEFT) {
        if((animation->getY()>10 && animation->getX()<70 && animation->getY()<83)||(animation->getY()<38 && animation->getX()==155)) {
            animation->setVelocity(0, 0);
        }else {
            animation->setVelocity(-1, 0);
        }
    } else if(keys & KEY_RIGHT) {
        if((animation->getY()<38 && animation->getX()==75)||(animation->getY()<75 && animation->getY()>10 && animation->getX()==160)) {
            animation->setVelocity(0, 0);
        }else{
            animation->setVelocity(1,0);
        }
    } else if(keys & KEY_UP) {
        if((animation->getX()>75 && animation->getX()<155 && animation->getY() < 38)||(animation->getY()<83 && animation->getY()>10 && animation->getX()<70)||(animation->getY()<75 && animation->getY()>15 && animation->getX()>160)) {
            animation->setVelocity(0, 0);
        }else {
            animation->setVelocity(0, -1);
        }
    } else if(keys & KEY_DOWN) {
        if(animation->getY()>110||(animation->getY()<83 && animation->getY()>10 && animation->getX()<70)||(animation->getY()<70 && animation->getY()>10 && animation->getX()>160)) {
            animation->setVelocity(0, 0);
        }else {
            animation->setVelocity(0, 1);
        }
    } else{
        animation->setVelocity(0, 0);
    }

    //naar een minigame gaan
        //minigame 1
    if(animation->getY()>70 && animation->getY()<100 && animation->getX()>20 && animation->getX()<50) {
        if(keys & KEY_A) {
            engine->setScene(new MiniGame1(engine));
        }
    }
        //minigame 2
    if(animation->getY()>37 && animation->getY()<68 && animation->getX()>100 && animation->getX()<130) {
        if(keys & KEY_A) {
            engine->setScene(new MiniGame2(engine));
        }
    }
        //minigame 3
    if(animation->getY()>74 && animation->getY()<104 && animation->getX()>185 && animation->getX()<215) {
        if(keys & KEY_A) {
            engine->setScene(new MiniGame3(engine));
        }
    }
}
