#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>

#include "MiniGame1.h"
#include "GameRoom.h"
#include "StartScene.h"
#include "CollorPallet.h"
#include "RPCselect.h"

MiniGame1::MiniGame1(const std::shared_ptr<GBAEngine> &engine) : Scene(engine) {}

//blad steen schaar

std::vector<Sprite *> MiniGame1::sprites() {
    return {
        RPC.get()
    };
}

std::vector<Background *> MiniGame1::backgrounds() {
    return {
        bg.get()
    };
}

void MiniGame1::tick(u16 keys) {
    //ga terug naar main map
    if(keys & KEY_L){
        engine->setScene(new StartScene(engine));
       // StartScene::totaalscore = StartScene::totaalscore + score1;
    }

    TextStream::instance().setText("score:" + std::to_string(score1), 3, 1);

    //keuze blad steen of schaar
    if(keys & KEY_UP){
        RPC->animateToFrame(3);
    }else if( keys & KEY_LEFT) {
        RPC->animateToFrame(2);
    }else if( keys & KEY_RIGHT){
        RPC->animateToFrame(1);
    }

    //spel spelen (blad steen schaar)
    if(keys & KEY_A && pressed == 0){
        TextStream::instance().clear();
        randnum = rand()%100;
        if(randnum<33){
            TextStream::instance().setText("It's a random generator,", 1, 1);
            TextStream::instance().setText("you got lucky!! ", 2, 1);
            score1=score1+100;
        }else if(randnum > 66){
            TextStream::instance().setText("great minds think alike", 1, 1);
            TextStream::instance().setText("", 2, 1);
        }else{
            TextStream::instance().setText("Only one can be the best", 1, 1);
            TextStream::instance().setText("", 2, 1);
            if(score1 > 50) {
                score1 = score1-50;
            }else{
                score1 = 0;
            }
        }
        pressed = 1;
    }

    if(!keys&KEY_A){
        pressed = 0;
    }
}

void MiniGame1::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(huisje_1Pal, sizeof(huisje_1Pal)));


    engine.get()->enableText();

    bg = std::unique_ptr<Background>(new Background(1, huisje_1Tiles, sizeof(huisje_1Tiles), huisje_1Map, sizeof(huisje_1Map)));
    bg.get()->useMapScreenBlock(16);

    SpriteBuilder<Sprite> builder;

    RPC = builder
            .withData(RPCselectTiles, sizeof(RPCselectTiles))
            .withSize(SIZE_32_32)
            .withLocation(80, 80)
            .buildPtr();

    RPC->animateToFrame(3);
}