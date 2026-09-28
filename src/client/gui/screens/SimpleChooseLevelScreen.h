#ifndef NET_MINECRAFT_CLIENT_GUI_SCREENS__DemoChooseLevelScreen_H__
#define NET_MINECRAFT_CLIENT_GUI_SCREENS__DemoChooseLevelScreen_H__

#include "ChooseLevelScreen.h"
#include "../components/TextBox.h"
#include "../components/Button.h"
class Button;
class ImageButton;

struct WorldGenSettings {
	int terrainType;
	float terrainScale;
	float seaLevel;

	bool generateStructures;
	bool generateCaves;
	bool generateOres;
	bool generateVegetation;
	bool generateWater;
	bool generateLava;

	int biomeDiversity;
	float biomeScale;

	bool spawnMobs;
	bool enableRain;
	bool enableNight;

	std::string presetName;

	WorldGenSettings()
	: terrainType(0),
	  terrainScale(1.0f),
	  seaLevel(64.0f),
	  generateStructures(true),
	  generateCaves(true),
	  generateOres(true),
	  generateVegetation(true),
	  generateWater(true),
	  generateLava(true),
	  biomeDiversity(2),
	  biomeScale(1.0f),
	  spawnMobs(true),
	  enableRain(true),
	  enableNight(true),
	  presetName("Custom")
	{
	}
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
	int currentTab;
	void renderBasicTab(int xm, int ym);
	void renderTerrainTab(int xm, int ym);
	void renderFeaturesTab(int xm, int ym);
	void renderBiomesTab(int xm, int ym);
	void renderMobsWeatherTab(int xm, int ym);
	void loadPreset(int presetIndex);
	void applyPreset();
	static std::string trimString(const std::string& value);
	static long hashString(const std::string& value);
	static float parseFloatValue(const std::string& value, float fallback);

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
	WorldGenSettings worldSettings;

	TextBox tLevelName;
	TextBox tSeed;
	TextBox tTerrainScale;
	TextBox tSeaLevel;
	TextBox tBiomeScale;
	TextBox tPresetName;
};

#endif /*NET_MINECRAFT_CLIENT_GUI_SCREENS__DemoChooseLevelScreen_H__*/
