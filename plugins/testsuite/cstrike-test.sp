#include <sourcemod>
#include <cstrike>
#include <sdktools>

public OnPluginStart()
{
	RegConsoleCmd( "get_mvps",         get_mvps        );
	RegConsoleCmd( "set_mvps",         set_mvps        );
	RegConsoleCmd( "get_score",        get_score       );
	RegConsoleCmd( "set_score",        set_score       );
	RegConsoleCmd( "get_assists",      get_assists     );
	RegConsoleCmd( "set_assists",      set_assists     );
	RegConsoleCmd( "get_clantag",      get_clantag     );
	RegConsoleCmd( "set_clantag",      set_clantag     );
	RegConsoleCmd( "get_teamscore",    get_teamscore   );
	RegConsoleCmd( "set_teamscore",    set_teamscore   );
	RegConsoleCmd( "translated_alias", translated_alias );
    RegConsoleCmd( "alias_to_id",      alias_to_id      );
    RegConsoleCmd( "id_to_alias",      id_to_alias      );
    RegConsoleCmd( "is_valid_id",      is_valid_id      );
    RegConsoleCmd( "get_weapon_price", get_weapon_price );
    RegConsoleCmd( "drop_weapon",      drop_weapon      );
    RegConsoleCmd( "respawn_player",   respawn_player   );
    RegConsoleCmd( "switch_team",      switch_team      );
    RegConsoleCmd( "terminate_round",  terminate_round  );
    RegConsoleCmd( "update_model",     update_model     );
}

public Action:get_mvps( client, argc )
{
	ReplyToCommand( client, "Your MVP count is %d", CS_GetMVPCount( client ) );
	
	return Plugin_Handled;
}

public Action:set_mvps( client, argc )
{
	int count = GetCmdArgInt( 1 );
	
	CS_SetMVPCount( client, count );
	ReplyToCommand( client, "Set your MVP count to %d", count );
	
	return Plugin_Handled;
}

public Action:get_score( client, argc )
{
	ReplyToCommand( client, "Your contribution score is %d", CS_GetClientContributionScore( client ) );

	return Plugin_Handled;
}

public Action:set_score( client, argc )
{
	int count = GetCmdArgInt( 1 );
	
	CS_SetClientContributionScore( client, count );
	ReplyToCommand( client, "Set your contribution score to %d", count );

	return Plugin_Handled;
}

public Action:get_assists( client, argc )
{
	ReplyToCommand( client, "Your assist count is %d", CS_GetClientAssists( client ) );

	return Plugin_Handled;
}

public Action:set_assists( client, argc )
{
	int count = GetCmdArgInt( 1 );
	
	CS_SetClientAssists( client, count );
	ReplyToCommand( client, "Set your assist count to %d", count );

	return Plugin_Handled;
}

public Action:get_clantag( client, argc )
{
	char tag[64];

	CS_GetClientClanTag( client, tag, sizeof(tag) );
	ReplyToCommand( client, "Your clan tag is: %s", tag );

	return Plugin_Handled;
}

public Action:set_clantag( client, argc )
{
	char tag[64];
	GetCmdArg( 1, tag, sizeof(tag) );

	CS_SetClientClanTag( client, tag );
	ReplyToCommand( client, "Set your clan tag to: %s", tag );

	return Plugin_Handled;
}

public Action:get_teamscore( client, argc )
{
	int tscore = CS_GetTeamScore( CS_TEAM_T );
	int ctscore = CS_GetTeamScore( CS_TEAM_CT );

	ReplyToCommand( client, "Team Scores: T = %d, CT = %d", tscore, ctscore );

	return Plugin_Handled;
}

public Action:set_teamscore( client, argc )
{
	int team = GetCmdArgInt( 1 );
	int score = GetCmdArgInt( 2 );

	if ( team != CS_TEAM_T && team != CS_TEAM_CT )
	{
		ReplyToCommand( client, "Team number must be %d or %d", CS_TEAM_T, CS_TEAM_CT );
		return Plugin_Handled;
	}

	CS_SetTeamScore( team, score );
	SetTeamScore( team, score );
	ReplyToCommand( client, "Score for team %d has been set to %d", team, score );

	return Plugin_Handled;
}

public Action:translated_alias( client, argc )
{
	char alias[64];
	GetCmdArg(1, alias, sizeof(alias));

	char weapon[64];
	CS_GetTranslatedWeaponAlias(alias, weapon, sizeof(weapon));
	ReplyToCommand(client, "CS_GetTranslatedWeaponAlias(\"%s\") = \"%s\"", alias, weapon);
}

public Action:alias_to_id( client, argc )
{
	char alias[64];
	GetCmdArg(1, alias, sizeof(alias));

	int id = CS_AliasToWeaponID(alias);
	ReplyToCommand(client, "CS_AliasToWeaponID(\"%s\") = %d", alias, id);
}

public Action:id_to_alias( client, argc )
{
	CSWeaponID id = view_as<CSWeaponID>(GetCmdArgInt(1));

	char alias[64];
	CS_WeaponIDToAlias(id, alias, sizeof(alias));
	ReplyToCommand(client, "CS_WeaponIDToAlias(%d) = \"%s\"", id, alias);
}

public Action:is_valid_id( client, argc )
{
	CSWeaponID id = view_as<CSWeaponID>(GetCmdArgInt(1));

	bool valid = CS_IsValidWeaponID(id);
	ReplyToCommand(client, "CS_IsValidWeaponID(%d) = \"%s\"", id, valid ? "true" : "false");
}

public Action:get_weapon_price( client, argc )
{
	CSWeaponID id = view_as<CSWeaponID>(GetCmdArgInt(1));
	int is_default = GetCmdArgInt(2);

	int price = CS_GetWeaponPrice(client, id, is_default);
	ReplyToCommand(client, "CS_GetWeaponPrice(%d) = \"%s\"", id, price);
}

public Action:drop_weapon( client, argc )
{
	int index = GetCmdArgInt(1);
	int toss = GetCmdArgInt(2);
	int block = GetCmdArgInt(3);
	CS_DropWeapon(client, index, toss, block);
}

public Action:respawn_player( client, argc )
{
	CS_RespawnPlayer(client);
}

public Action:switch_team( client, argc )
{
	int team = GetCmdArgInt(1);
	CS_SwitchTeam(client, team);
}

public Action:terminate_round( client, argc )
{
	float delay = GetCmdArgFloat(1);
	CSRoundEndReason reason = view_as<CSRoundEndReason>(GetCmdArgInt(2));
	int block = GetCmdArgInt(3);
	CS_TerminateRound(delay, reason, block);
}

public Action:update_model( client, argc )
{
	CS_UpdateClientModel(client);
}
