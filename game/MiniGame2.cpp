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
    }

    if(story == 0){
        if(level == 0) {
            TextStream::instance().setText("how do you put an elephant in a fridge?", 3, 1);
            TextStream::instance().setText("A: first the ele than the phant", 4, 1);
            TextStream::instance().setText("B: open the fridge, elephant in the fridge, close the fridge", 5, 1);
            if(keys&KEY_A){
                TextStream::instance().setText("What? how would you split the elephant", 3, 1);
                if(score > 50) {
                    score -= 50;
                }else {
                    score = 0;
                }
            }else if(keys & KEY_B){
                level = 1;
                score += 50;
            }
        }else if(level == 1) {
            TextStream::instance().setText("Good guess, but how do you put an giraf in a fridge?", 3, 1);
            TextStream::instance().setText("A: open the fridge, giraf in the fridge, close the fridge", 4, 1);
            TextStream::instance().setText("B: open the fridge, elephant out of the fridge, giraf in, close the fridge", 5, 1);
            if(keys&KEY_A){
                TextStream::instance().setText("What? An elephant and a giraf in 1 fridge? Think", 3, 1);
                if(score > 50) {
                    score -= 50;
                }else {
                    score = 0;
                }
            }else if(keys & KEY_B){
                level = 2;
                score += 50;
            }
        }else if(level == 2) {
            TextStream::instance().setText("The lion gives a party, who doesn't come?", 3, 1);
            TextStream::instance().setText("A: The giraf", 4, 1);
            TextStream::instance().setText("B: The elephant", 5, 1);
            if(keys&KEY_B){
                TextStream::instance().setText("What? He is out the fridge...", 3, 1);
                if(score > 50) {
                    score -= 50;
                }else {
                    score = 0;
                }
            }else if(keys & KEY_A){
                level = 3;
                score += 50;
            }
        }else if(level == 3) {
            TextStream::instance().setText("How to cross a croc infested lake?", 3, 1);
            TextStream::instance().setText("A: Just go and pray", 4, 1);
            TextStream::instance().setText("B: Walk to the broken bridge", 5, 1);
            if(keys&KEY_A){
                score += 50;
                level = 4;
            }else if(keys & KEY_B){
                TextStream::instance().setText("Think, where are the crocs?",3,1);
                if(score > 50) {
                    score -= 50;
                }else {
                    score = 0;
                }
            }
        }else if(level ==4){
            TextStream::instance().setText("The crocs are at the party...", 3, 1);
            TextStream::instance().setText("You finished my test", 4, 1);
            TextStream::instance().setText("You can leave now", 5, 1);
        }
    }

    if(story == 1){
        if(level == 0) {
            TextStream::instance().setText(".sdrawkcab noitseuq siht rewsna", 3, 1);
            TextStream::instance().setText("A: KO", 4, 1);
            TextStream::instance().setText("B: Tennis Elbow", 5, 1);
            if(keys&KEY_A){
                TextStream::instance().setText("rewsna gnorw", 3, 1);
                if(score > 50) {
                    score -= 50;
                }else {
                    score = 0;
                }
            }else if(keys & KEY_B){
                level = 1;
                score += 50;
            }else if(level == 1) {
                TextStream::instance().setText("What is the 7th letter of the alphabet?", 3, 1);
                TextStream::instance().setText("A: G", 4, 1);
                TextStream::instance().setText("B: H", 5, 1);
                if(keys&KEY_B){
                    TextStream::instance().setText("What? learn to count...", 3, 1);
                    if(score > 50) {
                        score -= 50;
                    }else {
                        score = 0;
                    }
                }else if(keys & KEY_A){
                    level = 2;
                    score += 50;
                }
            }else if(level == 2) {
                TextStream::instance().setText("gamble round", 3, 1);
                TextStream::instance().setText("A: this is correct", 4, 1);
                TextStream::instance().setText("B: this is correct", 5, 1);
                if(keys & KEY_A){
                    TextStream::instance().setText("Well it was 50/50", 3, 1);
                    if(score > 50) {
                        score -= 50;
                    }else {
                        score = 0;
                    }
                }else if(keys & KEY_B){
                    level = 3;
                    score += 50;
                }
            }else if(level == 3) {
                TextStream::instance().setText("how do you call a wingless fly?", 3, 1);
                TextStream::instance().setText("A: Jason", 4, 1);
                TextStream::instance().setText("B: A walk", 5, 1);
                if(keys&KEY_A){
                    TextStream::instance().setText("Not every life deserves a name.", 3, 1);
                    if(score > 50) {
                        score -= 50;
                    }else {
                        score = 0;
                    }
                }else if(keys & KEY_B){
                    level = 4;
                    score += 50;
                }
            }else if(level ==4){
                TextStream::instance().setText("What are you still doing here.", 3, 1);
                TextStream::instance().setText("You finished my test.", 4, 1);
                TextStream::instance().setText("You can leave now.", 5, 1);
            }
        }

        if(story == 2) {
            if (level == 0) {
                TextStream::instance().setText("can you get this question wrong", 3, 1);
                TextStream::instance().setText("A: I can", 4, 1);
                TextStream::instance().setText("B: Of course not", 5, 1);
                if (keys & KEY_A) {
                    TextStream::instance().setText("Have some confidence", 3, 1);
                    if (score > 50) {
                        score -= 50;
                    } else {
                        score = 0;
                    }
                } else if (keys & KEY_B) {
                    level = 1;
                    score += 50;
                } else if (level == 1) {
                    TextStream::instance().setText("pronounciation of GIF:", 3, 1);
                    TextStream::instance().setText("A: Gif", 4, 1);
                    TextStream::instance().setText("B: Jif", 5, 1);
                    if (keys & KEY_B) {
                        TextStream::instance().setText("You belong in hell", 3, 1);
                        if (score > 50) {
                            score -= 50;
                        } else {
                            score = 0;
                        }
                    } else if (keys & KEY_A) {
                        level = 2;
                        score += 50;
                    }
                } else if (level == 2) {
                    TextStream::instance().setText("where does DNA stand for", 3, 1);
                    TextStream::instance().setText("A: DeoxyriboNucleicAcid", 4, 1);
                    TextStream::instance().setText("B: National Dyslectic Association", 5, 1);
                    if (keys & KEY_A) {
                        TextStream::instance().setText("correct not", 3, 1);
                        if (score > 50) {
                            score -= 50;
                        } else {
                            score = 0;
                        }
                    } else if (keys & KEY_B) {
                        level = 3;
                        score += 50;
                    }
                } else if (level == 3) {
                    TextStream::instance().setText("Die hard is a christmas movie", 3, 1);
                    TextStream::instance().setText("A: Yipee ka yay motherf*cker", 4, 1);
                    TextStream::instance().setText("B: No", 5, 1);
                    if (keys & KEY_B) {
                        TextStream::instance().setText("Home alone nerd!", 3, 1);
                        if (score > 50) {
                            score -= 50;
                        } else {
                            score = 0;
                        }
                    } else if (keys & KEY_A) {
                        level = 4;
                        score += 50;
                    }
                } else if (level == 4) {
                    TextStream::instance().setText("You achieved something.", 3, 1);
                    TextStream::instance().setText("lost precious life minutes", 4, 1);
                    TextStream::instance().setText("You can leave now.", 5, 1);
                }
            }
        }
    }
}

void MiniGame2::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(huisje_2Pal, sizeof(huisje_2Pal)));

    engine.get()->enableText();

    bg = std::unique_ptr<Background>(new Background(0, huisje_2Tiles, sizeof(huisje_2Tiles), huisje_2Map, sizeof(huisje_2Map)));
    bg.get()->useMapScreenBlock(24);

    story = (rand()%2);
    level = 0;
}