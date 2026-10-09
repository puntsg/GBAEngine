#include "bn_core.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_text_generator.h"
#include "common_variable_8x16_sprite_font.h"
#include "bn_bg_palettes.h"
//Scenes
#include "GBAEngine/Scenes/Scene.h"
#include "GBAEngine/Scenes/SceneManager.h"

class MainMenuScene : public Scene
{
public:
    MainMenuScene() = default;
    ~MainMenuScene() = default;
    void OnEnter() override {
        bn::bg_palettes::set_transparent_color(bn::color(0, 0, 31));

        bn::sprite_text_generator text_generator(common::variable_8x16_sprite_font);
        text_generator.set_center_alignment();
        text_generator.generate(0, 0, "Gayardo, hola", text_sprites);
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
        SM.UpdateCurrentScene();
        bn::core::update();
    }
}
