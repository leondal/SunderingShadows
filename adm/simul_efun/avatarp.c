/**
 * @file
 */

/**
 * Is object an avatar?
 */
int avatarp(object ob)
{
    string set_by;
    if((string)ob->query_position() == "avatar") return 1;
    if(stringp(set_by = ob->query("is_valid_npc")) && "/adm/daemon/user_call.c"->user_call(set_by, "query_position") == "dm") return 1;
    if(wizardp(ob)) return 1;
    return 0;
}
