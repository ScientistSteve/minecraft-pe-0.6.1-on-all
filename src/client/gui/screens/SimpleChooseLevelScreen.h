#ifndef NET_MINECRAFT_CLIENT_GUI_SCREENS__DemoChooseLevelScreen_H__
#define NET_MINECRAFT_CLIENT_GUI_SCREENS__DemoChooseLevelScreen_H__

#include "ChooseLevelScreen.h"
#include "../components/TextBox.h"
#include "../components/Button.h"    // for Touch::THeader
class Button;
class ImageButton;

// World Generation Settings Structure
struct WorldGenSettings {
	// Terrain Generation
	int terrainType;			// 0=Default, 1=Flat, 2=Large Biomes, 3=Amplified
	float terrainScale;			// 0.5 to 2.0
	float seaLevel;				// 0 to 256
	
	// Feature Generation
	bool generateStructures;	// Villages, Temples, etc.
	bool generateCaves;			// Underground caves
	bool generateOres;			// Ore generation
	bool generateVegetation;	// Trees, grass, flowers
	bool generateWater;			// Lakes and rivers
	bool generateLava;			// Lava lakes
	
	// Biome Settings
	int biomeDiversity;			// 0=Tiny, 1=Small, 2=Medium, 3=Large
	float biomeScale;			// Biome transition size
	
	// Mob & Weather
	bool spawnMobs;				// Natural mob spawning
	bool enableRain;			// Weather system
	bool enableNight;			// Day/night cycle
	
	// Custom Preset
	std::string presetName;		// Name of the preset
	
	WorldGenSettings() :
		terrainType(0), terrainScale(1.0f), seaLevel(64.0f),
		generateStructures(true), generateCaves(true), generateOres(true),
		generateVegetation(true), generateWater(true), generateLava(true),
		biomeDiversity(2), biomeScale(1.0f),
		spawnMobs(true), enableRain(true), enableNight(true),
		presetName("Custom") {}
};

class SimpleChooseLevelScreen: public ChooseLevelScreen
{
public:
	SimpleChooseLevelScreen(const std::string& levelName);

	virtual ~SimpleChooseLevelScreen();

	void init();
	void setupPositions();
	void tick();

	void render(int xm, int ym, float a);

	void buttonClicked(Button* button);
	bool handleBackEvent(bool isDown);
	virtual void keyPressed(int eventKey);
	virtual void mouseClicked(int x, int y, int buttonNum);

private:
	// UI Navigation
	int currentTab;				// 0=Basic, 1=Terrain, 2=Features, 3=Biomes, 4=Mobs/Weather
	void renderBasicTab(int xm, int ym);
	void renderTerrainTab(int xm, int ym);
	void renderFeaturesTab(int xm, int ym);
	void renderBiomesTab(int xm, int ym);
	void renderMobsWeatherTab(int xm, int ym);
	void loadPreset(int presetIndex);
	void applyPreset();
	
	// UI Elements
	Touch::THeader* bHeader;
	Button* bTabBasic;
	Button* bTabTerrain;
	Button* bTabFeatures;
	Button* bTabBiomes;
	Button* bTabMobs;
	
	Button* bGamemode;
	Button* bCheats;
	Button* bGenerateStructures;
	Button* bGenerateCaves;
	Button* bGenerateOres;
	Button* bGenerateVegetation;
	Button* bGenerateWater;
	Button* bGenerateLava;
	Button* bSpawnMobs;
	Button* bEnableRain;
	Button* bEnableNight;
	
	ImageButton* bBack;
	Button* bCreate;
	Button* bLoadPreset;
	Button* bSavePreset;
	
	bool hasChosen;

	std::string levelName;
	int gamemode;
	bool cheatsEnabled;

	// World Generation Settings
	WorldGenSettings worldSettings;
	
	// Textboxes
	TextBox tLevelName;
	TextBox tSeed;
	TextBox tTerrainScale;
	TextBox tSeaLevel;
	TextBox tBiomeScale;
	TextBox tPresetName;
};

#endif /*NET_MINECRAFT_CLIENT_GUI_SCREENS__DemoChooseLevelScreen_H__*/
