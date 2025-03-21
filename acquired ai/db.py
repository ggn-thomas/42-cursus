from typing import Optional, List, Dict, Any
from datetime import datetime
from pydantic import BaseModel, Field, EmailStr
from bson import ObjectId
from enum import enum

class GenderCategory(str, Enum):
	MEN = "Men's sizing"
	WOMEN = "Women's sizing"

class WomenBodyType(str, Enum):
	HOURGLASS = "Hourglass"
	TRIANGLE = "Triangle"
	INVERTED_TRIANGLE = "Inverted triangle"
	RECTANGLE = "Rectangle"
	ROUND = "Round"
	DIAMOND = "Diamond"

class MenBodyType(str, Enum):
	ECTOMORPH = "Ectomorph"
	MESOMORPH = "Mesomorph"
	ENDOMORPH = "Endomorph"

class WomenFitChallenges(str, Enum):
	FULLER_BUST = "Fuller bust"
	BROADER_SHOULDERS = "Broader shoulders"
	FULLER_HIPS_OR_THIGHS = "Fuller hips or thighs"
	EXTRA_ROOM_WAIST = "Extra room in the waist"
	EXTRA_ROOM_ARMS = "Extra room in the arms"
	NONE = "none of the above"

class MenFitChallenges(str, Enum):
	FULLER_CHEST = "Fuller chest"
	BROADER_SHOULDERS = "Broader shoulders"
	EXTRA_ROOM_WAIST = "Extra room in the waist"
	EXTRA_ROOM_THIGHS = "Extra room in the thighs"
	LONG_SHORT_ARM = "Longer or shorter arms"
	LONG_SHORT_LEG = "Longer or shorter legs"
	NONE = "none of the above"

class WomenFitPreferences(str, Enum):
	BUST = "Bust"
	WAIST = "Waist"
	SHOULDERS = "Shoulders"
	HIPS_THIGHS = "Hips/Thighs"
	ARMS = "Arms"

class MenFitPreferences(str, Enum):
	BUST = "Bust"
	WAIST = "Waist"
	SHOULDERS = "Shoulders"
	THIGHS = "Thighs"
	ARMS = "Arms"
	CHEST = "Chest"

class WomenProportionPriorities(str, Enum):
	LONG_TORSOS = "Longer torsos in tops and dresses."
	SHORTER_TORSOS = "Shorter torsos in tops and dresses."
	SHORTER_SLEEVE = "Shorter sleeve lengths."
	LONGER_SLEEVE = "Longer sleeve lengths."
	LONGER_SKIRTS_DRESSES = "Longer/full length skirts and dresses."

class MenProportionPriorities(str, Enum):
	LONG_TORSOS = "Longer torsos in shirts and jackets"
	SHORTER_TORSOS = "Shorter torsos in shirts and jackets"
	SHORTER_SLEEVE = "Shorter sleeve lengths."
	LONGER_SLEEVE = "Longer sleeve lengths."
	LONGER_PANTS = "Longer/full-length pants"
	SHORTER_PANTS = "Shorter pants"

class DifferentSizes(str, Enum):
	UK = "UK size"
	US = "US size"
	EU = "EU size"
	BUST_INCHES = "Bust (inches)"
	BUST_CM = "Bust (cm)"

class FabricAllergies(str, Enum):
	COTTON = "Cotton"
	WOOL = "Wool"
	POLYESTER = "Polyester"
	SYNTHETIC = "Synthetic blends"
	OTHER = "Other (input field)"

class AcquiredHelpYou(str, Enum):
	SIZE_FOR_BODY = "Choosing the right size for my body type."
	BRAND_DISCOVERY = "Discovering brands that match my style and budget."
	REDUCE_SHOPPING_TIME = "Reducing the time spent shopping online."
	OVERCOMING_DECISION_FATIGUE = "Overcoming decision fatigue when shopping for fashion."
	PERSONALIZED_RECOMMENDATIONS = "Finding personalized fashion recommendations."
	CURATED_OUTFITS = "Finding curated outfits for specific occasions (e.g., work, events)."
	HELP = "Help me return less."
	ABANDON_CART = "I abandon my carts too much."
	OTHER = "Other (with an optional text box)"
