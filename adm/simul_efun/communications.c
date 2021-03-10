varargs void say(mixed str, object ob) 
{
    object ob2, ob3, *targs;
    if(!objectp(this_player()))
    {
        if(!objectp(previous_object()))
        {
            return;
        }
        ob2 = previous_object();
        while(objectp(environment(ob2)))
        {
            ob3 = ob2;
            ob2 = environment(ob2);
        }
    } 
    else 
    {
       ob3 = this_player();       
    }
    targs = ({});
    if(!objectp(environment(ob3))) return;
    if(objectp(ob3)) targs += ({ob3});
    if(objectp(ob2)) targs += ({ob2});
    if(objectp(ob)) targs += ({ob});
    
    message("tell", str+"", environment(ob3), targs);
}


void tell_object(object ob, mixed str) { if(!objectp(ob)) { return; } else { message("tell", str+"", ob); } }

varargs void tell_room(object ob, mixed str, mixed exclude) 
{
    if(!objectp(ob)) return;
    message("environment", (str ? str+"" : ""), ob,
      (exclude ? (pointerp(exclude) ? exclude : ({exclude})) : ({})));
}

varargs void shout(mixed str, mixed exclude) 
{
    if(objectp(exclude)) exclude = ({ exclude });
    else if(!pointerp(exclude)) exclude = ({});
    if(this_player()) exclude += ({ this_player() });
    message("shout", str+"", users(), exclude);
}

