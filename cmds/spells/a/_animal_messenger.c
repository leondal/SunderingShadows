// animal messenger. Shamelessly hijacked from Ares' leet whispering wind spell. Nienne, 05/08.
#include <priest.h>
inherit SPELL;

#define CREATURES ({"rat","chipmunk","squirrel","bunny","mouse","raven","pigeon","cat","weasel"})
string creature;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("animal messenger");
    set_spell_level(([ "ranger" : 1,"druid" : 2 ]));
    set_spell_sphere("divination");
    set_syntax("cast CLASS animal messenger on TARGET with the message TEXT");
    set_description("This spell will allow a ranger to attempt to send a brief message by way of a small creature, if any are around..");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_helpful_spell(1);
}

string query_cast_string() {
    tell_object(caster,"%^CYAN%^You offer a chirrup and some light clicks, trying to attract a nearby "
"creature.");
	tell_room(place,"%^CYAN%^"+caster->QCN+" makes a chirrup and some light clicks.",caster);
	return "display";
}

int preSpell(){
    string myterrain;
    myterrain = environment(caster)->query_terrain();
    if(myterrain == "city") {
      tell_object(caster,"%^BOLD%^%^GREEN%^No creature answers your call.");
      return 0;
    }
    if((int)environment(caster)->query_property("indoors")) {
      tell_object(caster,"%^BOLD%^%^GREEN%^No creature answers your call.");
      return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    string creature;
    object who;
    string *info,*mess=({}),message;
    int i;

    if(!arg) {
        tell_object(caster,"You must use the syntax: \n"
            "chant animal messenger to TARGET with the message <message>");
                dest_effect();
        return;
    }
    info = explode(arg," ");
    if(sizeof(info) < 5)
    {
        tell_object(caster,"You must use the syntax: \n"
            "chant animal messenger to TARGET with the message <message>");
		dest_effect();
        return;
    }
    // there has to be a more elegant way to do this...
    if(""+info[1]+" "+info[2]+" "+info[3]+"" != "with the message")   {
        tell_object(caster,"You must use the syntax: \n"
            "chant animal messenger to TARGET with the message <message>");
		dest_effect();
        return;
    }
    if(lower_case(info[0]) == (string)caster->query_true_name()) {
        tell_object(caster,"You realise it is likely pointless to send a message to yourself.");
		dest_effect();
        return;
    }
    creature = CREATURES[random(sizeof(CREATURES))];

    switch(creature){
        case "pigeon": case "raven":
	  tell_object(caster,"%^BOLD%^%^WHITE%^A "+creature+" swoops down from above, settling nearby.  You "
"convey your message to it in a series of whistles and chirps, and it takes off into the sky again.");
	  tell_room(environment(caster),"%^BOLD%^%^WHITE%^A "+creature+" swoops down from above, settling nearby"
".  "+caster->QCN+" utters a series of whistles and chirps, and it takes off into the sky again.",caster);
        break;

        default:
	  tell_object(caster,"%^BOLD%^%^WHITE%^A "+creature+" scampers in and comes to pause at your feet.  You "
"convey your message to it in a series of growls and chatter, and it scurries off again.");
	  tell_room(environment(caster),"%^BOLD%^%^WHITE%^A "+creature+" scampers in and comes to pause nearby.  "
+caster->QCN+" utters a series of growls and chatter, and it scurries off again.",caster);
        break;
    }

    if (!(who = find_player(caster->realName(lower_case(info[0])))) || (member_array((string)caster->query_true_name(), (string *)who->query_ignored()) != -1))     {
	  dest_effect();
        return;
    }

    if ((int)environment(who)->query_property("indoors") || who->query_invis())     {
	  dest_effect();
        return;
    }

    for(i=4;i<sizeof(info);i++) { mess += ({ info[i] }); }
    message = implode(mess," ");
    if(who->query_true_invis())    {
        tell_object(who,"%^BOLD%^"+caster->QCN+" just tried to send you the animal messenger "
            "message: "+message+"");
		dest_effect();
        return;
    }
    else if(who->query_unconscious()) {
	  dest_effect();
        return;
    }
    // might consider putting language checks here later
    else {
      switch(creature){
        case "pigeon": case "raven":
	  tell_object(who,"%^BOLD%^%^WHITE%^A "+creature+" swoops down from above, settling nearby.  It lets out "
"a series of whistles and chirps, and behind the noises you hear the voice of "+caster->QCN+" carried:"
"%^RESET%^ "+message+"");
	  tell_room(environment(who),"%^BOLD%^%^WHITE%^A "+creature+" swoops down from above, settling nearby, "
"and it lets out a series of whistles and chirps.",who);
        tell_room(environment(who),"%^BOLD%^%^WHITE%^With that, it takes off into the sky again.");
        break;

        default:
	  tell_object(who,"%^BOLD%^%^WHITE%^A "+creature+" scampers in and comes to pause at your feet.  It "
"lets out a series of growls and chatter, and behind the noises you hear the voice of "+caster->QCN+" carried:"
"%^RESET%^ "+message+"\n");
	  tell_room(environment(who),"%^BOLD%^%^WHITE%^A "+creature+" scampers in and comes to pause nearby, "
"letting out a series of growls and chatter.",who);
        tell_room(environment(who),"%^BOLD%^%^WHITE%^With that, it scurries off again.");
        break;
      }
    }
    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
