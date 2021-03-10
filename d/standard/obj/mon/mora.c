#include <std.h>

inherit MONSTER;
 
void create() {
    ::create();
    set_name("mora");
    set("id", ({ "mora", "medium", "fortune teller", "teller" }) );
    set("short", "Mora, the teller of fortunes");
    set("long",
        "She is spiritually on a plane beyond this reality.  "
        "A medium of the highest caliber, she tells the "
        "fortunes of those who come and seek her words.  "
        "It is 60 gold to \"horoscope\" yourself.  "
        "It is 100 gold for others."
    );
    set("race", "gnome");
    set_gender("female");
    set_body_type("human");
    set_hp(950);
    set_languages( ({ "nibelungen" }) );
    set_max_hp(950);
    set_mp(900);
    set_max_mp(900);
    set_level(17);
    set_stats("wisdom", 40);
    set_skill("magic attack", 100);
    set_speech(12, "nibelungen",
      ({
      "Come! Let me tell you your horoscope!",
      "Only 60 gold to know your horoscope.",
      "I am in touch with alternate realities.",
      "I can tell you the horoscope of your enemies.",
        "I am always spiritually well."
      }), 1
    );
    set_spell_chance(45);
    set_spells( ({ "blast" }) );
    set_alignment(-5);
    add_money("gold", random(60));
}
 
void init() {
    ::init();
    add_action("horoscope", "horoscope");
}
 
int horoscope(string str) {
    object ob;
    string msg;
    int mag, phy, cost;
 
    if(!str || str == "me" || str == "myself") ob = this_player();
    else ob = find_player(lower_case(str));
    if(!ob) {
        notify_fail("I cannot find "+capitalize(str)+".\n");
        return 0;
    }
    if(ob == this_player()) cost = 60;
    else cost = 110;
    if((int)this_player()->query_money("gold") < cost) {
        notify_fail("You do not have enough gold.\n");
        return 0;
    }
    mag = (int)ob->query_spiritual();
    phy = (int)ob->query_physical();
    this_player()->add_money("gold", -cost);
    write("You pay "+cost+" gold for Mora to give you a reading for today.");
    say(this_player()->query_cap_name()+" pays Mora for a horoscope reading.", this_player());
    switch(mag) {
        case -5:
          if(ob == this_player()) msg = "Spiritual reality is disconnected from your soul.";
          else msg = "Spiritual reality is disconnected from "+ob->query_possessive()+" soul.";
          break;
        case -4:
          if(ob == this_player()) msg = "You are feeling out of touch with spiritual reality.";
          else msg = capitalize(str)+" is feeling out of touch with spiritual reality.";
          break;
        case -3:
          if(ob == this_player()) msg = "Your soul is particularly weak today.";
          else msg = capitalize(str)+"'s soul is particularly weak today.";
          break;
        case -2:
          if(ob == this_player()) msg = "You are best advised not to rely on spiritual matters today.";
        else msg = capitalize(str)+" is best advised not to rely on spiritual matters today.";
          break;
        case -1:
          if(ob == this_player()) msg = "You will need to concentrate to excel spiritually.";
          else msg = capitalize(str)+" will need to concentrate to excel spiritually.";
          break;
        case 0:
          if(ob == this_player()) msg = "Today is an average day for you on the spiritual planes.";
          else msg = "Today is an average day for "+capitalize(str)+" on the spiritual planes.";
          break;
        case 1:
          if(ob == this_player()) msg = "You will need to do little to excel spiritually.";
          else msg = capitalize(str)+" will need to do a little to excel spiritually.";
          break;
        case 2:
          if(ob == this_player()) msg = "You will do well with your magic today.";
          else msg = capitalize(str)+" will do well with "+ob->query_possessive()+" magic today.";
          break;
        case 3:
          if(ob == this_player()) msg = "Your spiritual aura shines very strongly today.";
         else msg = capitalize(str)+"'s spiritual aura shines very strongly today.";
          break;
        case 4:
          if(ob == this_player()) msg = "You have an unusually radiant spiritual aura today.";
          else msg = capitalize(str)+" have and unusually radiant spiritual aura today.";
          break;
        case 5:
          if(ob == this_player()) msg = "No one should get in the way of your magic today.";
          else msg = "No one should get in the way of "+ob->query_possessive()+" magic today.";
          break;
    }
    write(""+msg);
    switch(phy) {
        case -5:
          if(ob == this_player()) msg = "You really should stay in bed today.";
          else msg = capitalize(str)+" really should stay in bed today.";
          break;
        case -4:
          if(ob == this_player()) msg = "You are feeling quite pathetic today.";
          else msg = capitalize(str)+" is feeling quite pathetic today.";
          break;
        case -3:
          if(ob == this_player()) msg = "It is not the best of days for your body.";
         else msg = "It is not the best of days for "+capitalize(str)+"'s body.";
          break;
        case -2:
          if(ob == this_player()) msg = "You are going to have a bad day with your body.";
          else msg = capitalize(str)+" is going to have a bad day with "+ob->query_possessive()+" body.";
          break;
        case -1:
          if(ob == this_player()) msg = "Your body is a bit under the weather today.";
          else msg = capitalize(str)+"'s body is a bit under the weather today.";
          break;
        case 0:
          if(ob == this_player()) msg = "You will do fine today.";
          else msg = capitalize(str)+" will be doing fine today.";
          break;
        case 1:
          if(ob == this_player()) msg = "You will do well today.";
          else msg = capitalize(str)+" will do well today.";
          break;
        case 2:
          if(ob == this_player()) msg = "Your physical strength is somewhat high.";
          else msg = capitalize(str)+"'s physical strength is somewhat high.";
          break;
        case 3:
          if(ob == this_player()) msg = "Today is a very robust day for you physically.";
          else msg = "Today is a very robust day for "+capitalize(str)+" physically.";
          break;
        case 4:
          if(ob == this_player()) msg = "You are in superior physical condition!";
          else msg = capitalize(str)+" is in superior physical condition!";
        break;
        case 5:
          if(ob == this_player()) msg = "Physically, you are in a rare top form.";
          else msg = "Physically, "+capitalize(str)+" is in a rare top form.";
          break;
    }
    write(""+msg);
    return 1;
}
