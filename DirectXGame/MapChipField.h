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


private:
	//1ブロックのサイズ
	static inline const float kBlockWidth = 1.0f;
	static inline const float kBlockHeight = 1.0f;

	//ブロックの個数
	static inline const uint32_t kNumBlockVertical = 20;
	static inline const uint32_t kNumBlockHorizontal = 100;
};

enum class MapChipType {
	kBlank,//空白
	kBlock,//ブロック
};

struct MapChipData {
	std::vector<std::vector<MapChipType>> data;
};


