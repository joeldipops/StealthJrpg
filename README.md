# StealthJrpg
Turn based stealth instead of combat

# Premise
You and your family have been rounded up and imprisoned (for some well developed politically charged reason to TBA).
Free your siblings/parents, escape the facility and eventually put a stop to whatever atrocities are taking place.

This is a stealth JRPG where the goal of turn-based battles is to sneak past or quietly disable enemies rather than attacking them head on with axes, gun-blades and fists.

# Battle Screen

- Ring of 8 tiles, plus 1 in the centre.  
- Any number of mobs can occupy each tile.
- Relative positions within a tile will be determined by order enterted and direction entered from.

# Win Conditions
- Reduce all Enemies Awareness (AWR) or Suspicion (SUS) to 0
- Occasionally, have all party members reach a certain tile.

# Lose Conditions
- All party member's Willpower (WIL) reduced to 0
- All members inflicted with CAUGHT status. 

# Progression
## Skill Trees
- Each party member has two main job branches, there may be much shorter branches here and there.
- Some smaller branches will be locked behind items, so sort of a combination of FF IX and X
  - For example, "Hack Cameras" may initially only be available when you have an item equipped.  But if you reach it in your skill tree and have the item available, you can then learn it permanently.


# Party Members
## Little Kid
Job Branches: Thief/Stealth, Hacker
- Highest Stealth
- Learns skills like Vanish
- Probably best at dealing with Cameras / Robots or whatever
- Out of combat, can crawl through vents 'n that.

## Teenager.
Job Branches: Healer, Ranged
- Highest Dexterity
- Gets skills affecting enemies at range such as Throw.

## Mother
Job Branches: Tank, Buffs 
- Let's give her best Speed and Highest Willpower.  Probably plays the role of tank??

## Father
Job Branches: Saboteur, Fighter
- Only party member able to really fight head-on
- Bit of a glass cannon
- Maybe he can also do some AOE effects that others can't (I'm thinking he has the strength to move heavy tables and stuff like that for barricades, or bust open doors or something)


# Stats
## PC Stats
### Willpower 
Essentially HP, but can be used to pay for skills as well. 

## Enemy Stats
### Suspicion
When at max, enemies will start to engage directly, dealing significant WIL damage and trying to inflict CAUGHT
When at 0, enemies will be idle.

### Awareness
When at 0, enemies are out of the encounter

### Direction
If looking at or near a PC, suspicion is more likely to be raised and skill effects more likely to hit that PC.

## Shared Stats

### Stealth
Need to develop idea further 
- Certain actions raise suspicion less if you have higher stealth
- And enemies less likely to target you

### Speed
Determines turn order

### Dexterity
### Intelligence
- Certain skills do more'damage'/less likely to fail.

### Agility
### Guts
- Certain enemy skills do less 'damage'/more likely to fail.

### Position
Which tile you occupy

# Skills
## Active Skills

### Use
Perform some environment specific action like flicking a switch. 

### Move
- Move to an adjacent tile
- Raise suspicion of enemies within certain range

### Hide
- Buffs Stealth

### Vanish 
- Gives Hidden status

## Disable
Lowers AWR of Electronic mobs when on same tile.

### Distract
- Raise enemies' SUS and cause their direction to change towards you.

### Throw Stone
- Raise enemies' SUS but cause their direction to change to wherever you choose.

### Throw (Item)
- Certain thrown consumables will have different effects on enemies.
- eg. Throw (Hack Dart) - allows a party member to use Disable (and other hacking skills?) on any enemies with Hack Dart's attached.

### Advanced forms of the previous 2 that cause the enemies to move as well.

(basic heals)
### Focus
- Restores own WIL but can raise SUS of nearby enemies.

### Rally
- Restores WIL of nearby PCs but can raise SUS of nearby enemies.

## Struggle Skills
Can only be used when in the Caught Status and only against the mob that caught you

### Scream
Inflicts DEAFENED with chance to be freed.

### Bite
Lowers AWR with chance to be freed.

## Passive Skills
Exist

# Conditions

## Blinded
Lowers max awareness

## Deafened
Also lowers max awareness, and stacks.

## Caught
- Certain skills disabled
- Other skills only available when caught.
- If all party members CAUGHT or DOWN, game over.

## Down
- When willpower at 0
- Unable to act
- If all party members CAUGHT or DOWN, game over.

## Quick/Slow
Can act more/less often

## Distracted
May be unable to act or use certain skills on a given turn

# Areas
## 1. Prison
- Starting area that you must escape from after picking up first party member "Teen".,
- Major mid-game dungeon to pick up party member'Father'

## 2. Forest
- Pass through here avoiding wild enemies and purusing foes after escaping from Prison and heading to the town.
- Later a side-quest area
- The Final Boss will be encountered in a remote part of the forest.

## 3. Town
- Major NPC and quest giving hub.
- Also houses some smaller dungeons.
- There will be times when you need to sneak around here 'fighting' random battles.

## 4. Base
- Major mid-game dungeon, Mother party member picked up here.
- Will return later gearing up towards the climax. 

## 5. Palace
- Major end-game dungeon

## 6. Plains/River
- Optional Sidequest area.

# Gameplay Outline

## Prologue - Prison
1. You start out as Little Kid alone
2. Over a few tutorial fights build up Move, Hide, Vanish and Disable skills.
3. Mostly fighting stationary Cameras, a Camera Drone here and some Rats for Training.
4. First miniboss has your first Human enemy as well as a bunch of Cameras.  Some USE action is required to dispense with the human.
5. Soon after you acquire the Distract skill, find Teenager and enter your first boss fight.
  - Teenager starts off CAUGHT, and you are introduced to Struggle Skills.
  - Will also need to use Distract to win  

### 1.A: Children's High Risk cells.
A spiral of cell blocks with a guard station at one end.
A few flavour NPCs and minor starting items such as money if you care to look everywhere.
Some text scratched in to the floor will teach you the basics of combat.  Reading it for the first time will initiate a tutorial battle with a **Rat**
Some scripted stuff and you'll be able to exit your cell. I suppose a guard falls asleep or gets sick, or there's some in-fighting or something. Whatever fits the ultimate direction and tone of the story.

Sneak around the cell blocks encountering **Rats** and eventually a **Camera** or two.
No guard will be in the guard house yet and you'll probably pick up a key item and some info there.

### 1.B Corridor to Children's High Risk
Pass through a corridor with small branches to various guard stations and cells along the way that may or may not have items flavour and fights.  You'll encounter **Camera**s and **Camera Drone**s

### 1.C Children's Exercise Room
First NPC area. Functions as your first 'town'.  Branching from here corridors *1.D Disused Corridor*, *1.E Small Maintenance Room*, *1.F Interrogation Block* *1.G Children's Mess* and *1.H Children's Clinic*

All these areas are hard-locked except for *1.D Disused Corridor* which you'll be able to enter after solving a puzzle/winning an encounter etc.

- There's an NPC that can sell you a map of the Children's part of the prison
- Another will give you detail about the areas.
- Flavour NPCs of course.
- A heal point.
- Some kind of item shop.
- A few NPCs that will help you put together where your family members are being held, especially your Brother.

### 1.D Disused Corridor
- Empty and seems like a dead-end.  Maybe some more **Camera**s and **Camera Drone**s.  
- At the end you'll fight a **Broken Camera** and will need to USE a Vent to progress.
- This will trip off some kind of Alarm, but you'll be safe in the Vent, which will take you to *1.E Small Maintenance Room*

### 1.E Small Maintenance Room
- You'll find an item that lets you use the DISABLE CAMERAS skill, which you'll need to progress.
- As you try to leave the room and move down the corridor a miniboss fight will be triggered with a **Camera**, **Camera Drone**s and a **Low Guard** who you'll just have to avoid for now.
- With DISABLE CAMERAS, you can beat the encounters blocking *1.F Interrogration Block*, *1.G Children's Mess* and *1.H Children's Clinic* but there's only some Flavour NPCs and some very minor items in the latter two for now.
- NPCs will point you toward the interrogation block

### 1.Fa Interrogration Block Corridor
- Avoid **Cameras**, and **Low Guards** as you make your way down the corridor.  The challenge will be increased here a bit.

### 1.Fb Interrogation Block
- Your brother is here.
- Some story ensues.
- Boss Fight with **Apprentice Interrogator** and a couple of **Low Guard**s
- Teen joins before the fight, but starts off CAUGHT and must use *Struggle Skills* before being able to help take out the enemies
- There are some Items around the fight that can be USEd to help too.



# Enemies

## Camera

## Camera Drone

## Broken Camera

## Low Guard

## Apprentice Interregator.









