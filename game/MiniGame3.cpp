#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>

#include "MiniGame3.h"
#include "GameRoom3.h"
#include "StartScene.h"
#include "CollorPallet.h"

MiniGame3::MiniGame3(const std::shared_ptr<GBAEngine> &engine) : Scene(engine) {}

std::vector<Sprite *> MiniGame3::sprites() {
    return {
    };
}

std::vector<Background *> MiniGame3::backgrounds() {
    return {
            bg.get()
    };
}

void MiniGame3::tick(u16 keys) {
    //ga terug naar main map
    if(keys & KEY_L){
        engine->setScene(new StartScene(engine));
    }
}

void MiniGame3::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(huisje_3Pal, sizeof(huisje_3Pal)));

    engine.get()->enableText();

    bg = std::unique_ptr<Background>(new Background(0, huisje_3Tiles, sizeof(huisje_3Tiles), huisje_3Map, sizeof(huisje_3Map)));
    bg.get()->useMapScreenBlock(24);
}