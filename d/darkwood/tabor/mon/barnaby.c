//barnaby - restored after I accidentally killed him. Circe 6/2/04
#include <std.h>
inherit NPC;
void create(){
    ::create();
    set_nwp("healing", 12);
    set_id(({"barnaby","healer","barnaby the healer"}));
    set_name("barnaby");
    set_short("Barnaby the Healer");
    set_long(
@CIRCE
Barnaby is an aging physician with wiry gray hair that is kept cut short but still seems to stick out in all directions.  He wears a thick leather apron with deep pockets, from which peek steel implements that look most unpleasant.  He is otherwise dressed all in white, and he bustles around the room, picking up small jars of leeches and tending to patients.  His hands are steady, if a little wrinkled, and he has developed a few dark age spots on his face, neck, and the backs of his hands.
CIRCE
    );
    set_race("human");
    set_body_type("human");
    set_gender("male");
    set_size(2);
    set_hd(19,2);
    set_hp(154);
    set_overall_ac(0);
    set_exp(100);
    set_alignment(1);
    set("aggressive",0);
}