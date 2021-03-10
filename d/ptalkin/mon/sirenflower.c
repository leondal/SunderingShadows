
//monsters by the House of Svaha

#include <std.h>

inherit MONSTER;

void create () {

        int resist;
::create();

set_name("%^YELLOW%^sirenflower");
set_id(({"sirenflower", "flower"}));
set_short("%^YELLOW%^sirenflower");
set_long(
@DESC
%^YELLOW%^This is a large carnivorous fungus that looks to be a normal
plant.  It captures its prey by luring victims towards its centre using
scent and lights.  The scent is like a thousand roses in full bloom
while the light is like the glow of candlelight."
DESC
);

set_race("plant");
set_gender("neuter");
set_size(1);
set_hd(10,10);
set_max_hp(90);
set_hp(90);
set_stats("strength", 18);
set_stats("constitution", 12);
set_stats("dexterity", 15);
set_stats("intelligence", 5);
set_stats("charisma", 15);
set_overall_ac(9);
set("aggressive", 15);
add_limb("branch 1", "branch 1",96,0,4);
add_limb("branch 2", "branch 2",96,0,4);
add_limb("branch 3", "branch 3",96,0,4);
add_limb("branch 4", "branch 4",96,0,4);
add_limb("branch 5", "branch 5",96,0,4);
add_limb("branch 6", "branch 6",96,0,4);
add_limb("branch 7", "branch 7",96,0,4);
add_limb("branch 8", "branch 8",96,0,4);
add_limb("branch 9", "branch 9",96,0,4);
add_limb("branch 10", "branch 10",96,0,4);
add_limb("branch 11", "branch 11",96,0,4);
add_limb("branch 12", "branch 12",96,0,4);
add_limb("branch 13", "branch 13",96,0,4);

set_wielding_limbs( ({"branch 1", "branch 2", "branch 3", "branch 4", "branch 5", "branch 6", "branch 7", "branch 8", "branch 9", "branch 10", "branch 11", "branch 12", "branch 13"}) );

new("/d/ptalkin/weapons/p_thorn")->move(this_object());
new("/d/ptalkin/weapons/p_thorn")->move(this_object());
new("/d/ptalkin/weapons/p_thorn")->move(this_object());
new("/d/ptalkin/weapons/p_thorn")->move(this_object());
new("/d/ptalkin/weapons/p_thorn")->move(this_object());
new("/d/ptalkin/weapons/p_thorn")->move(this_object());
new("/d/ptalkin/weapons/p_thorn")->move(this_object());
new("/d/ptalkin/weapons/p_thorn")->move(this_object());
new("/d/ptalkin/weapons/p_thorn")->move(this_object());
new("/d/ptalkin/weapons/p_thorn")->move(this_object());
new("/d/ptalkin/weapons/p_thorn")->move(this_object());
new("/d/ptalkin/weapons/p_thorn")->move(this_object());
new("/d/ptalkin/weapons/p_thorn")->move(this_object());

command("wield thorn 1 in branch 1");
command("wield thorn 2 in branch 2");
command("wield thorn 3 in branch 3");
command("wield thorn 4 in branch 4");
command("wield thorn 5 in branch 5");
command("wield thorn 6 in branch 6");
command("wield thorn 7 in branch 7");
command("wield thorn 8 in branch 8");
command("wield thorn 9 in branch 9");
command("wield thorn 10 in branch 10");
command("wield thorn 11 in branch 11");
command("wield thorn 12 in branch 12");
command("wield thorn 13 in branch 13");

set_funcs( ({"embrace"}) );

}
void embrace(object targ)
{
       if(!targ) return 0;
tell_room(environment(targ),"Branches reach out to grab at you, trapping you an
d slowly crushing you.", targ);
       targ->cause_typed_damage(targ, "torso", roll_dice(1, 20) + 4, "bludgeoning");
       targ->set_paralyzed(random(7),"You are temporarily paralyzed by the pain
");
       tell_object(targ,"Branches reach out from the sirenflower to gather you
closer to its heart, squeezing with great force, making it difficult to breathe.
",targ);
}
