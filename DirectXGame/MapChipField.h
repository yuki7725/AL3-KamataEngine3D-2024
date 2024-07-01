#pragma once
#include "Model.h"
#include "WorldTransform.h"
#include "ViewProjection.h"
#include "cassert"



/// <summary>
/// マップチップフィールド
/// </summary>
class MapChipField {
public:
	
	MapChipData mapChipData_;
	
	void ResetMapChipData();

	void LoadMapChipCsv(const std::string& filePath);
	
	MapChipType GetMapChipTypeByIndex(uint32_t xIndex, uint32_t yIndex);
	Vector3 GetMapChipPositionByIndex(uint32_t xIndex, uint32_t yIndex);

	//1ブロックのサイズ
	static inline const float kBlockWidth = 1.0f;
	static inline const float kBlockHeight = 1.0f;

	//ブロックの個数
	static inline const uint32_t kNumBlockVertical = 20;
	static inline const uint32_t kNumBlockHorizontal = 100;

	uint32_t GetNumBlockVertical();

private:
};

enum class MapChipType {
	kBlank,//空白
	kBlock,//ブロック
};

struct MapChipData {
	std::vector<std::vector<MapChipType>> data;
};


