#pragma once
#include "GBAEngine/Entities/Object.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_items_rowlet.h"


class Rowlet: public Object {
public:
    bn::sprite_ptr sprite;
    // (el double size mode per defecte és AUTO: Butano dobla l'espai sol quan el sprite rota)
    Rowlet(): sprite(bn::sprite_items::rowlet.create_sprite(0, 0)) {}
    ~Rowlet() = default;
    void OnEnable() override {

    }
    void OnDisable() override {

    }
    void Update() override {
        // Prova: girar 2 graus per frame (treure-ho quan hi hagi Rigidbody)
        transform.rotation += 2;
        if (transform.rotation >= 360) transform.rotation -= 360;

        // Copiar el Transform al sprite
        sprite.set_position(transform.position);
        sprite.set_rotation_angle(transform.rotation);
    }
};
