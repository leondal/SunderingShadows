//~Circe~ 7/30/05
//This power will allow the psion to open a portal, allowing
//people to travel between two places.
#include <spell.h>
#include <teleport.h>
#include <magic.h>
inherit SPELL;

void open_portal();
object endplace;

void create(){
    ::create();
    set_spell_name("planar portal");
    set_spell_level(([ "psion" : 7 ]));
    set_discipline("nomad");
    set_spell_sphere("psychoportation");
    set_syntax("cast CLASS planar portal to <location>");
    set_description("This potent power enables a nomad to open up a portal, allowing beings to pass from the place he "
"currently stands to one he has locked firmly in his memory.  By using this power, the nomad commands a temporary "
"connection between the two locations.  The power is taxing, however, so the portal will not remain open very long.  An "
"example of the power's usage is <remember here as cave>.  Then later on, the nomad would type, <manifest planar portal "
"to cave>.  Again, you may also <unremember cave> to forget that particular location.\n\nSee also: remember, unremember, "
"recall");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_casting_time(2);
    set_components(([
      "psion" : ([ "blue amethyst" : 1, "moonstone" : 1, "obsidian" : 1, ]),
    ]));
    set_helpful_spell(1);
}

string query_cast_string(){
   return "%^BOLD%^%^WHITE%^"+caster->QCN+" places one small piece each of "+
      "%^BOLD%^%^BLUE%^blue amethyst%^WHITE%^, %^RESET%^moonstone"+
      "%^BOLD%^, and %^BLACK%^obsidian%^WHITE%^ on the ground in "+
      "a triangle.%^RESET%^";
}

void spell_effect(int prof){
    string a = arg, file, tempstr, *tempdir;
    int mypower,startpower,endpower,bonus;
    mapping tmp;
    tempstr = ARG;
    spell_successful();
    if (!tempstr) {
        tell_object(caster,"You lose concentration on your power "+
          "as you realize you did not focus on a destination.");
        tell_room(place,caster->QCN+" looks confused.",caster);
        TO->remove();
        return;
    }
    if(!pointerp(caster->query_rem_rooms_sort()))
    {
        tell_object(caster,"You lose concentration on your power "+
          "as you realize you do not know a place named "+a+".");
        tell_room(place,caster->QCN+" looks confused.",caster);
        TO->remove();
        return;
    }
    if(member_array(a, caster->query_rem_rooms_sort()) < 0)
    {
        tell_object(caster,"You lose concentration on your power "+
          "as you realize you do not know a place named "+a+".");
        tell_room(place,caster->QCN+" looks confused.",caster);
        TO->remove();
        return;
    }
    tmp = caster->query_rem_rooms();
    file = tmp[a];

    if (!file || !stringp(file)) {
        tell_object(caster,"You lose concentration on your power "+
          "as you realize you do not know a place named "+a+".");
        tell_room(place,caster->QCN+" looks confused.",caster);
        TO->remove();
        return;
    }

    if (file) {
        if (!(endplace = find_object_or_load(file)))
            file = 0;
    }
    if (endplace &&
         (endplace->query_property("no teleport") ||
          place->query_property("no teleport") ||
          !endplace->is_room()) ) {
        file = 0;
    }
//teleport proof stuff by ~Circe~ 6/20/08
//new property to be used for areas protected from teleport
//but not foolproof
   if(endplace &&
      (endplace->query_property("teleport proof") ||
      place->query_property("teleport proof") ||
      !endplace->is_room())){
      startpower = place->query_property("teleport proof");
      endpower = endplace->query_property("teleport proof");
      bonus = caster->query_stats("intelligence");
      bonus = bonus -10;
      if((object *)caster->query_attackers() != ({})){
         mypower = CLEVEL + bonus + random(6);
      }else{
         mypower = CLEVEL + bonus + random(6) + 5;
//making it easier to teleport out if you aren't in combat
      }
      if((mypower < startpower) || (mypower < endpower)){
          file = 0;
      }
   }
    if (!file) {
        tell_object(caster,"You sense some sort of interference "+
           "blocking your way.");
        tell_room(place,caster->QCN+" looks confused.",caster);
        TO->remove();
        return;
    }
    if(endplace->is_flight_room())
    {
        tell_object(caster,"You sense something blocking your "+
                    "passage and lose concentration on your power.");
        tell_room(place,caster->QCN+" "+
                  "looks startled.",caster);
        TO->remove();
        return;
    }
    if(place == endplace){
        tell_object(caster,"The power fails as you try to open "+
           "a portal onto the same place you stand.");
        tell_room(place,caster->QCN+" looks confused.",caster);
        TO->remove();
        return;
    }
    spell_successful();
    tell_object(caster,"%^BOLD%^%^CYAN%^You concentrate on your "+
       "destination, firmly fixing it in your mind as you spread "+
       "your hands palms down over the stones.");
    tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" stands with "+
       ""+caster->QP+" hands spread palms down over the stones.",caster);
    call_out("do_portal",3,endplace);
    return;
}

void do_portal(object endplace){
    if (!caster) {
        dest_effect();
        return;
    }
    caster->removeAdminBlock();
    if (caster->query_ghost()) { dest_effect(); return;}

    if (!endplace) {
        tell_object(caster,"You sense some sort of interference "+
           "blocking your way.");
        tell_room(place,caster->QCN+" looks confused.",caster);
        dest_effect();
        return;
    }
    tell_room(place,"%^BOLD%^%^BLUE%^The stones begin to glow softly "+
       "before a beam of %^YELLOW%^light %^BLUE%^begins shining "+
       "upward from them, tiny %^YELLOW%^crystalline motes %^BLUE%^"+
       "rising up from the stones.");
    call_out("do_next",2+random(3), endplace);
    return;
}

void do_next(object endplace){
    string newplace;
    if (!caster) {
        dest_effect();
        return;
    }
    caster->removeAdminBlock();
    if (caster->query_ghost()) { dest_effect(); return;}

    if (!endplace) {
        tell_object(caster,"You sense some sort of interference "+
           "blocking your way.");
        tell_room(place,caster->QCN+" looks confused.",caster);
        dest_effect();
        return;
    }
    newplace = endplace->query_short();
    if(!newplace) newplace = "a room";
    tell_room(place,"%^BOLD%^%^MAGENTA%^%^The light suddenly %^B_MAGENTA%^"+
       "%^YELLOW%^flashes%^RESET%^ %^BOLD%^%^MAGENTA%^and a portal opens, leading "+
       "to "+newplace+"!");
    open_portal();
    call_out("dest_effect",clevel * ROUND_LENGTH);
    return;
}

int open_portal(){
   addSpellToCaster();
   tell_room(endplace,"%^BOLD%^A shimmering portal opens in the air!");
   endplace->add_exit(base_name(place), "portal");
   place->add_exit(base_name(endplace), "portal");
   return 1;
}

int close_portal(){
   tell_room(endplace,"%^BOLD%^%^BLACK%^The portal shimmers briefly, "+
      "then closes and fades away.");
   tell_room(place,"%^BOLD%^%^BLACK%^The portal shimmers briefly, "+
      "then closes and fades away.");
   place->remove_exit("portal");
   endplace && endplace->remove_exit("portal");
   return 1;
}

void dest_effect() {
    close_portal();
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
