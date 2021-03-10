//removed mention of non-specialized mages ~Circe~ 8/2/19
#include <magic.h>
#include <std.h>
#include <spell.h>
#include <daemons.h>
inherit SPELL;

object control;

void check();
void make_image();

void create() {
    ::create();
    set_spell_name("project image");
    set_spell_level(([ "mage" : 7, "bard" : 6,"oracle":7 ]));
    set_mystery("whimsy");
    set_spell_sphere("illusion");
    set_syntax("cast CLASS project image on TARGET");
    set_description("This spell will conjure an illusionary image of the caster, which will seek out the specified target "
"and convey the caster's thoughts by way of its own speech.  Likewise, it will convey the words of the target back to the "
"caster.  To speak to the target, the caster should use the <tell> and <reply> commands as per telepathy effects.  Any "
"attack upon the image will cause it to dissipate.  You can be rid of the image with <dismiss image>.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
     // school specific mage spell
	set_helpful_spell(1);
}

int preSpell() {
	if(caster->query_property("projected image")) {
        tell_object(caster, "%^CYAN%^You are incapable of controlling more than one projected image.%^RESET%^");
        return 0;
      }
      return 1;
}

string query_cast_string(){
   tell_object(caster,"%^CYAN%^You trace a complex pattern in the air before you.%^RESET%^");
   tell_room(place,"%^CYAN%^"+caster->QCN+" traces a complex pattern in the air.%^RESET%^",caster);
   return "display";
}

void spell_effect(int prof){
    string arg, *ignored, whoname, whocname, cname, Ccname;

    arg = lower_case(ARG);
    if (!(target = find_player(caster->realNameVsProfile(arg)))) {
        tell_object(CASTER,capitalize(arg)+" cannot be found to establish a link.\n");
        TO->remove();
        return;
    }
    cname = CASTER->query_name();
    whoname = target->query_name();
    whocname = target->QCN;
    Ccname = CASTER->QCN;
    if(target->query_true_invis()) {
        tell_object(CASTER,capitalize(arg)+" cannot be found to establish a link.\n");
        TO->remove();
        return;
    }
    if(target->query_disguised()) {
        tell_object(CASTER,capitalize(arg)+" cannot be found to establish a link.\n");
        TO->remove();
        return;
    }
    if(arg == cname) {
        tell_object(CASTER,"You cannot establish a link with yourself.\n");
        TO->remove();
        return;
    }
    if (target->query_invis() && (int)target->query_level() > (int)CASTER->query_level()) {
        tell_object(CASTER,capitalize(arg)+" cannot be found to establish a link.\n");
        TO->remove();
        return;
    }
    if (target->is_player() && !interactive(target)) {
        tell_object(CASTER, target->QCN+" is link-dead and cannot hear you.\n");
        TO->remove();
        return;
    }
    if (target->query_blocked("tell")) {
        write(target->QCN+" is currently blocking all tells.");
        TO->remove();
        return;
    }
    ignored = target->query_ignored();
    if (!ignored) {
        target->reset_ignored();
        ignored = target->query_ignored();
    }
    if ((member_array(cname, ignored) != -1)) {
        tell_object(CASTER, target->QCN+" is ignoring you.\n");
        TO->remove();
        return;
    }

	if(!objectp(environment(target))){
		dest_effect();
		return;
	}
      make_image();
      addSpellToCaster();
      call_out("check",ROUND_LENGTH);
      spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 2;
      set_end_time();
      call_out("dest_effect",spell_duration);
}

void check() {
      if(!objectp(control)) dest_effect();
      if(!objectp(control->query_image())) dest_effect();
      call_out("check",ROUND_LENGTH);
}

void make_image(){
    //added it so your projected image has
    //the same languages as you do - Saide
    int x;
    object ob;
    mapping langs;
    string shortdesc, pt2, long2, myname, *lnam;

    tell_object(caster,"%^CYAN%^The vague outline of a figure, already showing the mirrored features of yourself, appears "
"facing you.  You push your arms out as if to repel it, and it vanishes to seek its target.  You realise you can now "
"%^YELLOW%^<reply>%^RESET%^%^CYAN%^ to it, to communicate with "+target->QCN+".%^RESET%^");
    tell_room(place,"%^CYAN%^The vague outline of a figure appears facing "+caster->QCN+", and already showing "
+caster->QP+" mirrored features.  "+capitalize(caster->QS)+" pushes "+caster->QP+" arms out as if to repel it, and it "
"vanishes.%^RESET%^",caster);
    control = new("/d/magic/obj/imageremote");
    control->set_caster(caster);
    control->set_target(target);
    control->move(caster);
    control->set_property("spell",TO);
    control->set_property("spelled", ({TO}) );
    ob=new("/d/magic/obj/projectimg.c");
    control->set_image(ob);
    ob->set_caster(caster);
    ob->set_target(target);
    langs = caster->query_all_langs();
	//tell_object(find_player("saide"), identify(langs));
    lnam = keys(langs);
	//tell_object(find_player("saide"), identify(lnam));
    for(x = 0;x < sizeof(lnam);x++)
    {
      //tell_object(find_player("saide"), identify(lnam[x]) + identify(langs[lnam[x]]));
        ob->set_lang(lnam[x], langs[lnam[x]]);
        continue;
    }
    ob->force_me("speak "+(string)caster->query_language());
    pt2 = USERCALL->user_call((string)caster->query_name(),"getWholeDescriptivePhrase");
    pt2 = replace_string(pt2,"A","a",1);
    shortdesc = "%^RESET%^%^CYAN%^A wavering image of %^RESET%^"+pt2;
    pt2 = replace_string(pt2,"a","A",1);
    ob->set_short(shortdesc);
    ob->set_name("projected image");
    ob->set_id(({"summoned monster","image","projected image",(string)caster->query_race()}));
    ob->set_race((string)caster->query_race());
    ob->set_gender((string)caster->query_gender());
    myname = (string)target->knownAs(caster->query_name());
    if(!myname || myname == "") {
      long2 = pt2+" %^RESET%^%^GREEN%^"+(string)USERCALL->user_call((string)caster->query_name(),"query_description");
      ob->set_long(long2);
    }
    else {
      ob->add_id(myname);
      long2 = myname+" %^RESET%^%^GREEN%^"+(string)USERCALL->user_call((string)caster->query_name(),"query_description");
      ob->set_long(long2);
    }
    ob->move(environment(target));
    target->add_follower(ob);
    ob->set_property("spell",TO);
    ob->set_property("spell", ({TO}) );
    ob->set_property("spell_creature", TO);
    ob->set_property("minion", caster);
    caster->set_property("projected image",ob);
    tell_room(environment(target),"%^CYAN%^A wavering image of "+pt2+"%^RESET%^%^CYAN%^ appears before you!%^RESET%^");
}

void dest_effect() {
    object image;

    if (objectp(caster)) {
      tell_object(caster,"%^BOLD%^%^CYAN%^You sense your image fade away.%^RESET%^");
      caster->remove_property("projected image");
    }

    if(objectp(control)){
	if (objectp(image = control->query_image())){
		image->vanish();
		destruct(control);
	}
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
