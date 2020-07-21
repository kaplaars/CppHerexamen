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

//de speler krijgt verschillende keuzes en krijgt punten per juist antwoord

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
        StartScene::totaalscore = StartScene::totaalscore + score2;
    }

    if(!keys&KEY_ANY){
        pressed = 0;
        TextStream::instance().setText("score: " + std::to_string(score2), 3, 1);
    }

    TextStream::instance().setText("", 13, 1);

    if(story == 0){
        if(level == 0) {
            TextStream::instance().setText("how do you put ", 10, 1);
            TextStream::instance().setText("an elephant in a fridge?", 11, 1);
            TextStream::instance().setText("A: first ele than phant", 12, 1);
            TextStream::instance().setText("B: open the fridge, elephant", 13, 1);
            TextStream::instance().setText("in and close the fridge", 14, 1);
            if(keys&KEY_A && pressed == 0){
                TextStream::instance().setText("What? how would ", 10, 1);
                TextStream::instance().setText("you split the elephant", 11, 1);
                if(score2 > 50) {
                    score2 -= 50;
                }else {
                    score2 = 0;
                }
                pressed = 1;
            }else if(keys&KEY_B && pressed == 0){
                level = 1;
                score2 += 50;
                pressed = 1;
            }
        }else if(level == 1) {
            TextStream::instance().setText("Good guess, but how do you", 10, 1);
            TextStream::instance().setText("put a giraf in a fridge?", 11, 1);
            TextStream::instance().setText("A: open the fridge, giraf in", 12, 1);
            TextStream::instance().setText("and close the fridge", 13, 1);
            TextStream::instance().setText("B: open the fridge, elephant", 14, 1);
            TextStream::instance().setText("out, giraf in", 15, 1);
            TextStream::instance().setText("and close the fridge", 16, 1);
            if(keys&KEY_A && pressed == 0){
                TextStream::instance().setText("What? An elephant and", 10, 1);
                TextStream::instance().setText("a giraf in 1 fridge? Think", 11, 1);
                if(score2 > 50) {
                    score2 -= 50;
                }else {
                    score2 = 0;
                }
                pressed = 1;
            }else if(keys & KEY_B && pressed == 0){
                level = 2;
                score2 += 50;
                pressed = 1;
            }
        }else if(level == 2) {
            TextStream::instance().setText("The lion gives a party,", 10, 1);
            TextStream::instance().setText("who doesn't come?", 11, 1);
            TextStream::instance().setText("A: The giraf", 12, 1);
            TextStream::instance().setText("B: The elephant", 13, 1);
            TextStream::instance().setText("", 14, 1);
            TextStream::instance().setText("", 15, 1);
            TextStream::instance().setText("", 16, 1);
            if(keys & KEY_B && pressed == 0){
                TextStream::instance().setText("What? He is out the fridge...", 10, 1);
                if(score2 > 50) {
                    score2 -= 50;
                }else {
                    score2 = 0;
                }
                pressed = 1;
            }else if(keys & KEY_A && pressed == 0){
                level = 3;
                score2 += 50;
                pressed = 1;
            }
        }else if(level == 3) {
            TextStream::instance().setText("How to cross", 10, 1);
            TextStream::instance().setText("a croc infested lake?", 11, 1);
            TextStream::instance().setText("A: Just go and pray", 12, 1);
            TextStream::instance().setText("B: Walk to the broken bridge", 13, 1);
            if(keys&KEY_A && pressed == 0){
                score2 += 50;
                level = 4;
                pressed = 1;
            }else if(keys&KEY_B && pressed == 0){
                TextStream::instance().setText("Think, where are the crocs?",10,1);
                if(score2 > 50) {
                    score2 -= 50;
                }else {
                    score2 = 0;
                }
                pressed = 1;
            }
        }else if(level ==4){
            TextStream::instance().setText("The crocs are at the party...", 10, 1);
            TextStream::instance().setText("You finished my test", 11, 1);
            TextStream::instance().setText("You can leave now", 12, 1);
        }
    }else if(story == 1){
        if(level == 0) {
            TextStream::instance().setText("siht rewsna", 10, 1);
            TextStream::instance().setText(".sdrawkcab noitseuq", 11, 1);
            TextStream::instance().setText("A: KO", 12, 1);
            TextStream::instance().setText("B: Tennis Elbow", 13, 1);
            if (keys & KEY_B && pressed == 0) {
                TextStream::instance().setText("rewsna gnorw", 10, 1);
                if (score2 > 50) {
                    score2 -= 50;
                } else {
                    score2 = 0;
                }
                pressed = 1;
            } else if (keys & KEY_A && pressed == 0) {
                level = 1;
                score2 += 50;
                pressed = 1;
            }
        }else if(level == 1) {
            TextStream::instance().setText("What is the 7th letter", 10, 1);
            TextStream::instance().setText("of the alphabet?", 11, 1);
            TextStream::instance().setText("A: G", 12, 1);
            TextStream::instance().setText("B: H", 13, 1);
            if (keys & KEY_B && pressed == 0) {
                TextStream::instance().setText("What? learn to count...", 10, 1);
                if (score2 > 50) {
                    score2 -= 50;
                } else {
                    score2 = 0;
                }
                pressed = 1;
            } else if (keys & KEY_A && pressed == 0) {
                level = 2;
                score2 += 50;
                pressed = 1;
            }
        }else if(level == 2) {
                TextStream::instance().setText("gamble round", 10, 1);
                TextStream::instance().setText("A: this is correct", 11, 1);
                TextStream::instance().setText("B: this is correct", 12, 1);
                if(keys & KEY_A && pressed == 0){
                    TextStream::instance().setText("Well it was 50/50", 10, 1);
                    if(score2 > 50) {
                        score2 -= 50;
                    }else {
                        score2 = 0;
                    }
                    pressed = 1;
                }else if(keys & KEY_B && pressed == 0){
                    level = 3;
                    score2 += 50;
                    pressed = 1;
                }
        }else if(level == 3) {
                TextStream::instance().setText("how do you call", 10, 1);
            TextStream::instance().setText("a wingless fly?", 11, 1);
                TextStream::instance().setText("A: With a phone", 12, 1);
                TextStream::instance().setText("B: A walk", 13, 1);
                if(keys&KEY_A && pressed == 0){
                    TextStream::instance().setText("How can a fly phone?", 10, 1);
                    if(score2 > 50) {
                        score2 -= 50;
                    }else {
                        score2 = 0;
                    }
                    pressed = 1;
                }else if(keys & KEY_B && pressed == 0){
                    level = 4;
                    score2 += 50;
                    pressed = 1;
                }
        }else if(level ==4){
                TextStream::instance().setText("What are you still doing here.", 10, 1);
                TextStream::instance().setText("You finished my test.", 11, 1);
                TextStream::instance().setText("You can leave now.", 12, 1);
        }
    }else if(story == 2) {
        if (level == 0) {
            TextStream::instance().setText("can you get", 10, 1);
            TextStream::instance().setText("this question wrong", 11, 1);
            TextStream::instance().setText("A: I can", 12, 1);
            TextStream::instance().setText("B: Of course not", 13, 1);
            if (keys & KEY_A && pressed == 0) {
                TextStream::instance().setText("Have some confidence", 10, 1);
                if (score2 > 50) {
                    score2 -= 50;
                } else {
                    score2 = 0;
                }
                pressed = 1;
            } else if (keys & KEY_B && pressed == 0) {
                level = 1;
                score2 += 50;
                pressed = 1;
            }
        }else if (level == 1) {
                    TextStream::instance().setText("pronounciation of GIF:", 10, 1);
                    TextStream::instance().setText("A: Gif", 11, 1);
                    TextStream::instance().setText("B: Jif", 12, 1);
                    if (keys & KEY_B && pressed == 0) {
                        TextStream::instance().setText("You belong in hell", 10, 1);
                        if (score2 > 50) {
                            score2 -= 50;
                        } else {
                            score2 = 0;
                        }
                        pressed = 1;
                    } else if (keys & KEY_A && pressed == 0) {
                        level = 2;
                        score2 += 50;
                        pressed = 1;
                    }
                } else if (level == 2) {
                    TextStream::instance().setText("where does DNA stand for", 10, 1);
                    TextStream::instance().setText("A: DeoxyriboNucleicAcid", 11, 1);
                    TextStream::instance().setText("B: National Dyslectic", 12, 1);
                    TextStream::instance().setText("B:Association", 13, 1);
                    if (keys & KEY_A && pressed == 0) {
                        TextStream::instance().setText("correct not", 10, 1);
                        if (score2 > 50) {
                            score2 -= 50;
                        } else {
                            score2 = 0;
                        }
                        pressed = 1;
                    } else if (keys & KEY_B && pressed == 0) {
                        level = 3;
                        score2 += 50;
                        pressed = 1;
                    }
                } else if (level == 3) {
                    TextStream::instance().setText("Die hard is a christmas movie", 10, 1);
                    TextStream::instance().setText("A: Yipee ka yay motherf*cker", 11, 1);
                    TextStream::instance().setText("B: No", 12, 1);
                    if (keys & KEY_B && pressed == 0) {
                        TextStream::instance().setText("Home alone nerd!", 10, 1);
                        if (score2 > 50) {
                            score2 -= 50;
                        } else {
                            score2 = 0;
                        }
                        pressed = 1;
                    } else if (keys & KEY_A && pressed == 0) {
                        level = 4;
                        score2 += 50;
                        pressed = 1;
                    }
                } else if (level == 4) {
                    TextStream::instance().setText("You achieved something.", 10, 1);
                    TextStream::instance().setText("lost precious life minutes", 11, 1);
                    TextStream::instance().setText("You can leave now.", 12, 1);
                }
            }
        }

void MiniGame2::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(huisje_2Pal, sizeof(huisje_2Pal)));

    engine.get()->enableText();

    bg = std::unique_ptr<Background>(new Background(1, huisje_2Tiles, sizeof(huisje_2Tiles), huisje_2Map, sizeof(huisje_2Map)));
    bg.get()->useMapScreenBlock(16);

    if(engine->getTimer()->getMsecs()>666){
        story = 0;
    }else if(engine->getTimer()->getMsecs()<333){
        story = 1;
    }else{
        story = 2;
    }
    level = 0;
    pressed = 1;
    score2 = 0;
}