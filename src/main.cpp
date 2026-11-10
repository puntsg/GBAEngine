#include "bn_core.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_text_generator.h"
#include "common_variable_8x16_sprite_font.h"
#include "bn_bg_palettes.h"
#include "Rowlet.h"
//Scenes
#include "GBAEngine/Entities/Scene.h"
#include "GBAEngine/Managers/SceneManager.h"
#include "GBAEngine/Managers/PhysicsManager.h"


class MainMenuScene : public Scene
{
    
public:
    Rowlet rowlet;
    MainMenuScene(): Scene() {};
    ~MainMenuScene() = default;
    void OnEnter() override {
        bn::bg_palettes::set_transparent_color(bn::color(0, 0, 31));
        bn::sprite_text_generator text_generator(common::variable_8x16_sprite_font);
        text_generator.set_center_alignment();
        text_generator.generate(0, 0, "Tu madre tiene una polla", text_sprites);
        //rowlet = Rowlet();
    }
    void Update() override {
        Scene::Update();   // objects, spawner, ui...
        rowlet.Update();   // rowlet no és a 'objects', així que l'actualitzem a mà
    }

private:
     bn::vector<bn::sprite_ptr, 32> text_sprites;
};

int main()
{
    bn::core::init();

    MainMenuScene mainMenuScene;
    SM.AddScene("MainMenu", &mainMenuScene);
    SM.InitFirstScene("MainMenu");

    while(true)
    {
        PM.UpdatePhysics();
        SM.UpdateCurrentScene();
        bn::core::update();
    }
}
