//	/adm/simul_efun/tell_player.c
//	from the Nightmare mudlib
//	allows you to use the autowrap function with tell object
//	Concept by Plura@Nightmare
//	Code by Descartes of Borg

void tell_player(object player, string message) 
{
    if((string)player->getenv("autowrap") == "on") { message = "\n"+message; }
    tell_object(player, message);
}
