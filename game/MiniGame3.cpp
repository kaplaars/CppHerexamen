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
    TextStream::instance().setText(engine->getTimer()->to_string(), 3, 1);

    if(engine->getTimer()->to_string() == "0h:0m:30s:000"){
        TextStream::instance().setText("pres A", 3, 1);
    }
    if(engine->getTimer()->to_string() == "0h:0m:31s:000" && keys & KEY_A){
        score += 50;
    }

    if(engine->getTimer()->to_string() == "0h:0m:40s:000"){
        TextStream::instance().setText("pres B", 3, 1);
    }
    if(engine->getTimer()->to_string() == "0h:0m:41s:000" && keys & KEY_B){
        score += 50;
    }

    if(engine->getTimer()->to_string() == "0h:0m:45s:000"){
        TextStream::instance().setText("pres A", 3, 1);
    }
    if(engine->getTimer()->to_string() == "0h:0m:46s:000" && keys & KEY_A){
        score += 50;
    }

    if(engine->getTimer()->to_string() == "0h:0m:55s:000"){
        TextStream::instance().setText("pres B", 3, 1);
    }
    if(engine->getTimer()->to_string() == "0h:0m:56s:000" && keys & KEY_B){
        score += 50;
    }

    if(engine->getTimer()->to_string() == "0h:0m:58s:000"){
        TextStream::instance().setText("pres UP", 3, 1);
    }
    if(engine->getTimer()->to_string() == "0h:0m:59s:000" && keys & KEY_UP){
        score += 50;
    }

    if(engine->getTimer()->to_string() == "0h:0m:60s:000"){
        TextStream::instance().setText("pres DOWN", 3, 1);
    }
    if(engine->getTimer()->to_string() == "0h:0m:61s:000" && keys & KEY_DOWN){
        score += 50;
    }

    if(engine->getTimer()->to_string() == "0h:0m:65s:000"){
        TextStream::instance().setText("well done cowboy", 3, 1);
    }
}

void MiniGame3::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(huisje_3Pal, sizeof(huisje_3Pal)));

    engine.get()->enableText();

    bg = std::unique_ptr<Background>(new Background(1, huisje_3Tiles, sizeof(huisje_3Tiles), huisje_3Map, sizeof(huisje_3Map)));
    bg.get()->useMapScreenBlock(16);

    engine->getTimer()->start();
}