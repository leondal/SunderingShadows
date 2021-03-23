// whispering wind
// allows a simple message to be send in one direction from the caster to the target
// the caster has no way of knowing if the target recieves the message or not -Ares
// tweaked to take from array item 4 rather than 5, was skipping first word of message. nienne, 05/08.
#include <priest.h>

void create()
{
    ::create();
    set_author("ares");
    set_spell_name("whispering wind");
    set_spell_level(([ "bard" : 2, "mage" : 2, "inquisitor" : 2, "druid" : 1 ]));
    set_spell_sphere("divination");
    set_syntax("cast CLASS whispering wind on TARGET with the message <message>");
    set_description("This spell will allow the caster to attempt to send a brief message on the winds from them to their target.  The caster has no way of knowing if the target has heard their message.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_helpful_spell(1);
}

string query_cast_string()
{
    tell_object(caster, "%^BOLD%^%^BLUE%^Cupping your hands, you whisper into the air. " +
                "Suddenly a breeze blows through, carrying your words with it.");
    tell_room(place, "%^BOLD%^" + caster->QCN + " cups " +
              "" + caster->QP + " hands and whispers into the air.\n Suddenly a breeze" +
              " blows through, rustling " + caster->QCN + "'s clothing before it departs.", caster);
    return "display";
}

void spell_effect(int prof)
{
    object who;
    string *info,*mess=({}),message;
    int i;

    if(!arg)
    {
        tell_object(caster,"You need a message to send..\n"
            "syntax: cast CLASS whispering wind to TARGET with the message <message>");
        dest_effect();
        return;
    }
    info = explode(arg," ");
    if(sizeof(info) < 5){
        tell_object(caster,"You must use the syntax: \n"
            "cast CLASS whispering wind to TARGET with the message <message>");
		dest_effect();
        return;
    }
    // there has to be a more elegant way to do this...
    if(""+info[1]+" "+info[2]+" "+info[3]+"" != "with the message")
    {
        tell_object(caster,"You must use the syntax: \n"
            "cast CLASS whispering wind to TARGET with the message <message>");
		dest_effect();
        return;
    }

    if (!(who = find_player(caster->realName(lower_case(info[0])))))
    {
		tell_object(caster,"%^BOLD%^%^WHITE%^The winds stir as you send your "
			"message away on the breeze.");
		dest_effect();
        return;
    }
    if(lower_case(info[0]) == (string)caster->query_true_name())
    {
        tell_object(caster,"You whisper to yourself.");
		dest_effect();
        return;
    }

    if ((member_array((string)caster->query_true_name(), (string *)who->query_ignored()) != -1))
	{
		tell_object(caster,"%^BOLD%^%^WHITE%^The winds stir as you send your "
			"message away on the breeze.");
		dest_effect();
        return;
    }

    for(i=4;i<sizeof(info);i++) { mess += ({ info[i] }); }
    message = implode(mess," ");
    if(who->query_true_invis() || avatarp(who))
    {
		tell_object(caster,"%^BOLD%^%^WHITE%^The winds stir as you send your "
			"message away on the breeze.");
        tell_object(who,"%^BOLD%^"+caster->QCN+" just tried to send you the whispering wind "
            "message: "+message+"");
		dest_effect();
        return;
    }
    else if(who->query_unconscious())
    {
		tell_object(caster,"%^BOLD%^%^WHITE%^The winds stir as you send your "
			"message away on the breeze.");
		dest_effect();
        return;
    }
    // might consider putting language checks here later
    else
    {
		tell_object(caster,"%^BOLD%^%^WHITE%^The winds stir as you send your "
			"message away on the breeze.");
        tell_object(who,"%^BOLD%^%^BLUE%^A gentle breeze stirs around you,"+
		    " the sound of barely audible words carried on it.\n"+
		    "%^BOLD%^%^CYAN%^Upon the breeze, "+caster->QCN+"'s voice is "+
		    "carried with these words "+message+"\n");
		dest_effect();
        return;
    }
    return;
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
