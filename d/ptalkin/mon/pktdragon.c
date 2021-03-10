inherit "/std/monster";

create() {
  object fangs;
    ::create();
set_name("%^GREEN%^Pocket dragon");
set_id(({"pocket dragon", "dragon"}));
set_short("%^GREEN%^a pocket dragon");
set_level(10);
set_long("%^GREEN%^
The pocket dragon is a three foot long lizard that resembles a small
green dragon.  It is usually found resting on a small pile of treasure
and other shiny objects.  It is lazy and peaceful by nature feeding on
insects and plants and rarely attacks larger creatures
unless it is angered.  The creature shares with dragons a love of
hoarding treasure, but its sense of value is not as fine as its 
larger cousins.  Its treasure often consists of broken glass and
shiney trinkets.
%^RESET%^");
   set("race", "lizard");
   set_gender("male");
   set_body_type("quadruped");
   set_wielding_limbs(({"mouth"}));
   set_alignment(2);
   set("aggressive",20);
   set_size(1);
   set_stats("intelligence",6);
   set_stats("wisdom",4);
   set_stats("strength",5);
   set_stats("charisma",3);
   set_stats("dexterity",18);
   set_stats("constitution",14);
   set_max_mp(0);
   set_hd(3,1);
set_max_hp(query_hp());
set_max_sp(query_hp());
set_sp(query_max_sp());
   set_max_hp(query_hp());
   set_mp(query_max_mp());
set_wielding_limbs(({"mouth", "right forepaw", "left forepaw"}));
   new("/d/shadow/mon/obj/fangs")->move(this_object());
   this_object()->force_me("wield fangs in mouth"); 
new("/d/ptalkin/weapons/pktclaws")->move(this_object());
command("wield claws in right forepaw");
new("/d/ptalkin/weapons/pktclaws")->move(this_object());
command("wield claws in left forepaw");
}

