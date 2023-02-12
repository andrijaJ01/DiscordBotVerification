# Setup

```
sudo pacman -S ninja,cmake
```

##Token

If you don't already have a discord bot, click [here](https://discordapp.com/developers/), accept any prompts then click "New Application" at the top right of the screen.  Enter the name of your bot then click accept.  Click on Bot from the panel from the left, then click "Add Bot."  When the prompt appears, click "Yes, do it!" 
![Left panel](https://i.imgur.com/hECJYWK.png)

Then, click copy under token to get your bot's token. Your bot's icon can also be changed by uploading an image.

![Bot token area](https://i.imgur.com/da0ktMC.png)

###Getting started

Edit:

```
src/main.cpp
```
and edit following:

```
dpp::cluster bot("MTA3MTAyMTUxMTA0NzEzOTM5OA.GXCEx6.8hzlMnzXAt-wJCIijxShOPU3AkJl8ErIV0Yq2c");//TOKEN FOR BOT FROM DISCORD DEVELOPER PORTAL.Line 11
```

and 

```
  thistrole.guild_id = 1044859463494008862;
```
