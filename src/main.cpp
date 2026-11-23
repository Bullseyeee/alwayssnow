#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(AlwaysSnowMenuLayer, MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) return false;

		if (this->getChildByID("always-snow"_spr)) return true;

		int density = Mod::get()->getSettingValue<int64_t>("density");

		auto snow = CCParticleSnow::createWithTotalParticles(density);
		snow->setID("always-snow"_spr);
		snow->setPositionType(kCCPositionTypeFree);
		this->addChild(snow, 100);

		return true;
	}
};
