//Gwendolyn - healer for Lothwaite.  Circe 6/22/04
#include <std.h>
inherit NPC;
void create(){
    ::create();
    set_nwp("healing", 20);
    set_id(({"gwendolyn","healer","gwendolyn the healer","Gwendolyn"}));
    set_name("gwendolyn");
    set_short("Gwendolyn the Healer");
    set_long(
@CIRCE
Gwendolyn is an aging firbolg woman whose long %^ORANGE%^chestnut hair %^CYAN%^has become streaked with %^RESET%^gray%^CYAN%^.  Her hair is kept pulled into a bun aside from the %^BOLD%^%^RED%^b%^RESET%^%^ORANGE%^e%^YELLOW%^a%^GREEN%^d%^CYAN%^e%^BLUE%^d %^WHITE%^abrigon%^RESET%^%^CYAN%^ ending in a tiny wooden sword that dangles behind her left ear.  She is dressed in a simple %^ORANGE%^brown muslin dress %^CYAN%^that reaches her ankles, which are covered by soft %^ORANGE%^suede boots %^CYAN%^with %^BOLD%^%^WHITE%^white fur %^RESET%^%^CYAN%^bristling from the top.  She is clearly all about the business of healing, and she greets the injured with a gentle smile before turning to the serious matters of their wounds or illnesses.  It is likely she has been at her craft her entire life, and she is quite skilled at what she does.
CIRCE
    );
    set_race("firbolg");
    set_gender("female");
    set_size(3);
    set_hd(19,2);
    set_hp(200+random(50));
    set_overall_ac(-10);
    set_exp(100);
    set_alignment(1);
    set("aggressive",0);
}