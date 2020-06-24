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
    if(keys & KEY_L){
        engine->setScene(new StartScene(engine));
    }

    if(keys & KEY_UP){
        RPC->animateToFrame(0);
        selection = 0;
    }else if( keys & KEY_LEFT) {
        RPC->animateToFrame(1);
        selection = 1;
    }else if( keys & KEY_RIGHT){
        RPC->animateToFrame(2);
        selection = 2;
    }

    if(keys & KEY_A){
        randnum = rand()%100;
        if(randnum<33){
            TextStream::instance().setText("It's a random generator, you got lucky!! ", 3, 8);
        }else if(randnum > 66){
            TextStream::instance().setText("Only one can be the best", 3, 8);
        }else{
            TextStream::instance().setText("great minds thing alike, a tie", 3, 8);
        }
    }
}

void MiniGame1::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(huisje_1Pal, sizeof(huisje_1Pal)));


    engine.get()->enableText();

    bg = std::unique_ptr<Background>(new Background(0, huisje_1Tiles, sizeof(huisje_1Tiles), huisje_1Map, sizeof(huisje_1Map)));
    bg.get()->useMapScreenBlock(24);

    SpriteBuilder<Sprite> builder;

    RPC = builder
            .withData(RPCselectTiles, sizeof(RPCselectTiles))
            .withSize(SIZE_32_32)
            .withLocation(75, 110)
            .buildPtr();
}