#include <dpp/dpp.h>
#include <cstdlib>
#include <string>
#include <iostream>


std::string testCode = "TheCode";//replace this with actual way of accessing codes.

int main() {
//TOKEN
    dpp::cluster bot("MTA3MTAyMTUxMTA0NzEzOTM5OA.GXCEx6.8hzlMnzXAt-wJCIijxShOPU3AkJl8ErIV0Yq2c");//TOKEN FOR BOT FROM DISCORD DEVELOPER PORTAL.
        bot.on_log(dpp::utility::cout_logger());

    bot.on_slashcommand([&bot](const dpp::slashcommand_t & event) {
        if (event.command.get_command_name() == "verify") {
            std::string codeIn = std::get<std::string>(event.get_parameter("code"));

	    if(testCode==codeIn)//checks code provided by user and if it matches it will add role
        {
	    //code for role assignment

       auto role = dpp::find_role(1073684515270164581);

if (!role) {
  // Role does not exist, create the role
  dpp::role thistrole;
  thistrole.permissions = dpp::p_administrator;
  thistrole.guild_id = 1044859463494008862;
  thistrole.set_name("verified_user");
  bot.role_create(thistrole, [&bot, event](auto& e) {
    if (!e.is_error()) {
      dpp::role r = std::get<dpp::role>(e.value);
      bot.guild_member_add_role(event.command.guild_id, event.command.usr.id, r.id);
    }
  });
} else {
  // Role already exists?
  //use it NOT WORKING ATM

//dpp::role r = role->value();


    bot.guild_member_add_role(event.command.guild_id, event.command.usr.id, 1073684515270164581);

}
        event.reply(std::string("thanks for verifying"));




	    }
	    else{
		event.reply(std::string("please double check the code you have provided...\nMuch obliged\nServer staff"));
	    }
        }
    });

    bot.on_ready([&bot](const dpp::ready_t & event) {
        if (dpp::run_once<struct register_bot_commands>()) {

            dpp::slashcommand newcommand("verify", "Verifies code for further server access", bot.me.id);
	    newcommand.add_option(dpp::command_option(dpp::co_string,"code","Code for server access",true ));

            bot.global_command_create(newcommand);
        }
    });

    bot.start(dpp::st_wait);

    return 0;
}
