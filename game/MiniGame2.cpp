#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>

#include "MiniGame2.h"
#include "GameRoom2.h"
#include "StartScene.h"
#include "CollorPallet.h"

MiniGame2::MiniGame2(const std::shared_ptr<GBAEngine> &engine) : Scene(engine) {}

std::vector<Sprite *> MiniGame2::sprites() {
    return {
    };
}

std::vector<Background *> MiniGame2::backgrounds() {
    return {
            bg.get()
    };
}

void MiniGame2::tick(u16 keys) {
    //ga terug naar main map
    if(keys & KEY_L){
        engine->setScene(new StartScene(engine));
    }
}

void MiniGame2::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(huisje_2Pal, sizeof(huisje_2Pal)));

    engine.get()->enableText();

    bg = std::unique_ptr<Background>(new Background(0, huisje_2Tiles, sizeof(huisje_2Tiles), huisje_2Map, sizeof(huisje_2Map)));
    bg.get()->useMapScreenBlock(24);
}