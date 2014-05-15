//Code ported from GregTech API

#pragma once

namespace gt {
    ofstream fdump{"gtdump.txt"};
    enum textures {
        SET_LAPIS,
        SET_QUARTZ,
        SET_POWDER,
        SET_LIGNITE,
        SET_SAND,
        SET_FINE,
        SET_ROUGH,
        SET_METALLIC,
        SET_FLINT,
        SET_DIAMOND,
        SET_OPAL,
        SET_RUBY,
        SET_GEM_HORIZONTAL,
        SET_GEM_VERTICAL,
        SET_NETHERSTAR,
        SET_EMERALD,
        SET_SHINY,
        SET_DULL,
        SET_PAPER,
        SET_WOOD,
        SET_LEAF,
        SET_EMPTY,
        SET_NONE,
        SET_FLUID
    };
    struct dye {
        dye(int aColor, int aR, int aG, int aB, string aName) {

        }
    };
    namespace dyes {
        dye _NULL(-1, 255, 255, 255, "INVALID COLOR");
        dye Black(0, 32, 32, 32, "Black");
        dye Red(1, 255, 0, 0, "Red");
        dye Green(2, 0, 255, 0, "Green");
        dye Brown(3, 96, 64, 0, "Brown");
        dye Blue(4, 0, 0, 255, "Blue");
        dye Purple(5, 128, 0, 128, "Purple");
        dye Cyan(6, 0, 255, 255, "Cyan");
        dye LightGray(7, 192, 192, 192, "Light Gray");
        dye Gray(8, 128, 128, 128, "Gray");
        dye Pink(9, 255, 192, 192, "Pink");
        dye Lime(10, 128, 255, 128, "Lime");
        dye Yellow(11, 255, 255, 0, "Yellow");
        dye LightBlue(12, 128, 128, 255, "Light Blue");
        dye Magenta(13, 255, 0, 255, "Magenta");
        dye Orange(14, 255, 128, 0, "Orange");
        dye White(15, 255, 255, 255, "White");
    }
    struct element {
        element(int aProtons, int aNeutrons, int aAdditionalMass, int aHalfLifeSeconds, string aDecayTo, string aName) {}
    };
    namespace elements {
        element _NULL(0, 0, 0, -1, "", "");
        element H(1, 0, 0, -1, "", "Hydrogen");
        element D(1, 1, 0, -1, "H", "Deuterium");
        element T(1, 2, 0, -1, "D", "Tritium");
        element He(2, 2, 0, -1, "", "Helium");
        element He_3(2, 1, 0, -1, "H&D", "Helium-3");
        element Li(3, 4, 0, -1, "", "Lithium");
        element Be(4, 5, 0, -1, "", "Beryllium");
        element B(5, 5, 0, -1, "", "Boron");
        element C(6, 6, 0, -1, "", "Carbon");
        element N(7, 7, 0, -1, "", "Nitrogen");
        element O(8, 8, 0, -1, "", "Oxygen");
        element F(9, 9, 0, -1, "", "Fluorine");
        element Ne(10, 10, 0, -1, "", "Neon");
        element Na(11, 11, 0, -1, "", "Sodium");
        element Mg(12, 12, 0, -1, "", "Magnesium");
        element Al(13, 13, 0, -1, "", "Aluminium");
        element Si(14, 14, 0, -1, "", "Silicon");
        element P(15, 15, 0, -1, "", "Phosphorus");
        element S(16, 16, 0, -1, "", "Sulfur");
        element Cl(17, 18, 0, -1, "", "Chlorine");
        element Ar(18, 22, 0, -1, "", "Argon");
        element K(19, 20, 0, -1, "", "Potassium");
        element Ca(20, 20, 0, -1, "", "Calcium");
        element Sc(21, 24, 0, -1, "", "Scandium");
        element Ti(22, 26, 0, -1, "", "Titanium");
        element V(23, 28, 0, -1, "", "Vanadium");
        element Cr(24, 28, 0, -1, "", "Chrome");
        element Mn(25, 30, 0, -1, "", "Manganese");
        element Fe(26, 30, 0, -1, "", "Iron");
        element Co(27, 32, 0, -1, "", "Cobalt");
        element Ni(28, 30, 0, -1, "", "Nickel");
        element Cu(29, 34, 0, -1, "", "Copper");
        element Zn(30, 35, 0, -1, "", "Zinc");
        element Ga(31, 39, 0, -1, "", "Gallium");
        element Ge(32, 40, 0, -1, "", "Germanium");
        element As(33, 42, 0, -1, "", "Arsenic");
        element Se(34, 45, 0, -1, "", "Selenium");
        element Br(35, 45, 0, -1, "", "Bromine");
        element Kr(36, 48, 0, -1, "", "Krypton");
        element Rb(37, 48, 0, -1, "", "Rubidium");
        element Sr(38, 49, 0, -1, "", "Strontium");
        element Y(39, 50, 0, -1, "", "Yttrium");
        element Zr(40, 51, 0, -1, "", "Zirconium");
        element Nb(41, 53, 0, -1, "", "Niobium");
        element Mo(42, 53, 0, -1, "", "Molybdenum");
        element Tc(43, 55, 0, -1, "", "Technetium");
        element Ru(44, 57, 0, -1, "", "Ruthenium");
        element Rh(45, 58, 0, -1, "", "Rhodium");
        element Pd(46, 60, 0, -1, "", "Palladium");
        element Ag(47, 60, 0, -1, "", "Silver");
        element Cd(48, 64, 0, -1, "", "Cadmium");
        element In(49, 65, 0, -1, "", "Indium");
        element Sn(50, 68, 0, -1, "", "Tin");
        element Sb(51, 70, 0, -1, "", "Antimony");
        element Te(52, 75, 0, -1, "", "Tellurium");
        element I(53, 74, 0, -1, "", "Iodine");
        element Xe(54, 77, 0, -1, "", "Xenon");
        element Cs(55, 77, 0, -1, "", "Caesium");
        element Ba(56, 81, 0, -1, "", "Barium");
        element La(57, 81, 0, -1, "", "Lantanium");
        element Ce(58, 82, 0, -1, "", "Cerium");
        element Pr(59, 81, 0, -1, "", "Praseodymium");
        element Nd(60, 84, 0, -1, "", "Neodymium");
        element Pm(61, 83, 0, -1, "", "Promethium");
        element Sm(62, 88, 0, -1, "", "Samarium");
        element Eu(63, 88, 0, -1, "", "Europium");
        element Gd(64, 93, 0, -1, "", "Gadolinium");
        element Tb(65, 93, 0, -1, "", "Terbium");
        element Dy(66, 96, 0, -1, "", "Dysprosium");
        element Ho(67, 97, 0, -1, "", "Holmium");
        element Er(68, 99, 0, -1, "", "Erbium");
        element Tm(69, 99, 0, -1, "", "Thulium");
        element Yb(70, 103, 0, -1, "", "Ytterbium");
        element Lu(71, 103, 0, -1, "", "Lutetium");
        element Hf(72, 106, 0, -1, "", "Hafnium");
        element Ta(73, 107, 0, -1, "", "Tantalum");
        element W(74, 109, 0, -1, "", "Wolframium");
        element Re(75, 111, 0, -1, "", "Rhenium");
        element Os(76, 114, 0, -1, "", "Osmium");
        element Ir(77, 115, 0, -1, "", "Iridium");
        element Pt(78, 117, 0, -1, "", "Platinum");
        element Au(79, 117, 0, -1, "", "Gold");
        element Hg(80, 120, 0, -1, "", "Mercury");
        element Tl(81, 123, 0, -1, "", "Thallium");
        element Pb(82, 125, 0, -1, "", "Lead");
        element Bi(83, 125, 0, -1, "", "Bismuth");
        element Po(84, 124, 0, -1, "", "Polonium");
        element At(85, 124, 0, -1, "", "Astatine");
        element Rn(86, 134, 0, -1, "", "Radon");
        element Fr(87, 134, 0, -1, "", "Francium");
        element Ra(88, 136, 0, -1, "", "Radium");
        element Ac(89, 136, 0, -1, "", "Actinium");
        element Th(90, 140, 0, -1, "", "Thorium");
        element Pa(91, 138, 0, -1, "", "Protactinium");
        element U(92, 146, 0, -1, "", "Uranium");
        element U_235(92, 143, 0, -1, "", "Uranium-235");
        element Np(93, 144, 0, -1, "", "Neptunium");
        element Pu(94, 152, 0, -1, "", "Plutonium");
        element Pu_241(94, 149, 0, -1, "", "Plutonium-241");
        element Am(95, 150, 0, -1, "", "Americium");
        element Cm(96, 153, 0, -1, "", "Curium");
        element Bk(97, 152, 0, -1, "", "Berkelium");
        element Cf(98, 153, 0, -1, "", "Californium");
        element Es(99, 153, 0, -1, "", "Einsteinium");
        element Fm(100, 157, 0, -1, "", "Fermium");
        element Md(101, 157, 0, -1, "", "Mendelevium");
        element No(102, 157, 0, -1, "", "Nobelium");
        element Lr(103, 159, 0, -1, "", "Lawrencium");
        element Rf(104, 161, 0, -1, "", "Rutherfordium");
        element Db(105, 163, 0, -1, "", "Dubnium");
        element Sg(106, 165, 0, -1, "", "Seaborgium");
        element Bh(107, 163, 0, -1, "", "Bohrium");
        element Hs(108, 169, 0, -1, "", "Hassium");
        element Mt(109, 167, 0, -1, "", "Meitnerium");
        element Ds(110, 171, 0, -1, "", "Darmstadtium");
        element Rg(111, 169, 0, -1, "", "Roentgenium");
        element Cn(112, 173, 0, -1, "", "Copernicium");
        element Uut(113, 171, 0, -1, "", "Ununtrium");
        element Fl(114, 175, 0, -1, "", "Flerovium");
        element Uup(115, 173, 0, -1, "", "Ununpentium");
        element Lv(116, 177, 0, -1, "", "Livermorium");
        element Fa(117, 177, 0, -1, "", "Farnsium");
        element Uuo(118, 176, 0, -1, "", "Ununoctium");
        element Ma(0, 0, 100, -1, "", "Magic");
        element Nt(0, 1000, 0, -1, "", "Neutronium");
        element $H(-1, -0, 0, -1, "", "Anti-Hydrogen");
        element $D(-1, -1, 0, -1, "H", "Anti-Deuterium");
        element $T(-1, -2, 0, -1, "D", "Anti-Tritium");
        element $He(-2, -2, 0, -1, "", "Anti-Helium");
        element $He_3(-2, -1, 0, -1, "H&D", "Anti-Helium-3");
        element $Li(-3, -4, 0, -1, "", "Anti-Lithium");
        element $Be(-4, -5, 0, -1, "", "Anti-Beryllium");
        element $B(-5, -5, 0, -1, "", "Anti-Boron");
        element $C(-6, -6, 0, -1, "", "Anti-Carbon");
        element $N(-7, -7, 0, -1, "", "Anti-Nitrogen");
        element $O(-8, -8, 0, -1, "", "Anti-Oxygen");
        element $F(-9, -9, 0, -1, "", "Anti-Fluorine");
        element $Ne(-10, -10, 0, -1, "", "Anti-Neon");
        element $Na(-11, -11, 0, -1, "", "Anti-Sodium");
        element $Mg(-12, -12, 0, -1, "", "Anti-Magnesium");
        element $Al(-13, -13, 0, -1, "", "Anti-Aluminium");
        element $Si(-14, -14, 0, -1, "", "Anti-Silicon");
        element $P(-15, -15, 0, -1, "", "Anti-Phosphorus");
        element $S(-16, -16, 0, -1, "", "Anti-Sulfur");
        element $Cl(-17, -18, 0, -1, "", "Anti-Chlorine");
        element $Ar(-18, -22, 0, -1, "", "Anti-Argon");
        element $K(-19, -20, 0, -1, "", "Anti-Potassium");
        element $Ca(-20, -20, 0, -1, "", "Anti-Calcium");
        element $Sc(-21, -24, 0, -1, "", "Anti-Scandium");
        element $Ti(-22, -26, 0, -1, "", "Anti-Titanium");
        element $V(-23, -28, 0, -1, "", "Anti-Vanadium");
        element $Cr(-24, -28, 0, -1, "", "Anti-Chrome");
        element $Mn(-25, -30, 0, -1, "", "Anti-Manganese");
        element $Fe(-26, -30, 0, -1, "", "Anti-Iron");
        element $Co(-27, -32, 0, -1, "", "Anti-Cobalt");
        element $Ni(-28, -30, 0, -1, "", "Anti-Nickel");
        element $Cu(-29, -34, 0, -1, "", "Anti-Copper");
        element $Zn(-30, -35, 0, -1, "", "Anti-Zinc");
        element $Ga(-31, -39, 0, -1, "", "Anti-Gallium");
        element $Ge(-32, -40, 0, -1, "", "Anti-Germanium");
        element $As(-33, -42, 0, -1, "", "Anti-Arsenic");
        element $Se(-34, -45, 0, -1, "", "Anti-Selenium");
        element $Br(-35, -45, 0, -1, "", "Anti-Bromine");
        element $Kr(-36, -48, 0, -1, "", "Anti-Krypton");
        element $Rb(-37, -48, 0, -1, "", "Anti-Rubidium");
        element $Sr(-38, -49, 0, -1, "", "Anti-Strontium");
        element $Y(-39, -50, 0, -1, "", "Anti-Yttrium");
        element $Zr(-40, -51, 0, -1, "", "Anti-Zirconium");
        element $Nb(-41, -53, 0, -1, "", "Anti-Niobium");
        element $Mo(-42, -53, 0, -1, "", "Anti-Molybdenum");
        element $Tc(-43, -55, 0, -1, "", "Anti-Technetium");
        element $Ru(-44, -57, 0, -1, "", "Anti-Ruthenium");
        element $Rh(-45, -58, 0, -1, "", "Anti-Rhodium");
        element $Pd(-46, -60, 0, -1, "", "Anti-Palladium");
        element $Ag(-47, -60, 0, -1, "", "Anti-Silver");
        element $Cd(-48, -64, 0, -1, "", "Anti-Cadmium");
        element $In(-49, -65, 0, -1, "", "Anti-Indium");
        element $Sn(-50, -68, 0, -1, "", "Anti-Tin");
        element $Sb(-51, -70, 0, -1, "", "Anti-Antimony");
        element $Te(-52, -75, 0, -1, "", "Anti-Tellurium");
        element $I(-53, -74, 0, -1, "", "Anti-Iodine");
        element $Xe(-54, -77, 0, -1, "", "Anti-Xenon");
        element $Cs(-55, -77, 0, -1, "", "Anti-Caesium");
        element $Ba(-56, -81, 0, -1, "", "Anti-Barium");
        element $La(-57, -81, 0, -1, "", "Anti-Lantanium");
        element $Ce(-58, -82, 0, -1, "", "Anti-Cerium");
        element $Pr(-59, -81, 0, -1, "", "Anti-Praseodymium");
        element $Nd(-60, -84, 0, -1, "", "Anti-Neidymium");
        element $Pm(-61, -83, 0, -1, "", "Anti-Promethium");
        element $Sm(-62, -88, 0, -1, "", "Anti-Samarium");
        element $Eu(-63, -88, 0, -1, "", "Anti-Europium");
        element $Gd(-64, -93, 0, -1, "", "Anti-Gadolinium");
        element $Tb(-65, -93, 0, -1, "", "Anti-Terbium");
        element $Dy(-66, -96, 0, -1, "", "Anti-Dysprosium");
        element $Ho(-67, -97, 0, -1, "", "Anti-Holmium");
        element $Er(-68, -99, 0, -1, "", "Anti-Erbium");
        element $Tm(-69, -99, 0, -1, "", "Anti-Thulium");
        element $Yb(-70, -103, 0, -1, "", "Anti-Ytterbium");
        element $Lu(-71, -103, 0, -1, "", "Anti-Lutetium");
        element $Hf(-72, -106, 0, -1, "", "Anti-Hafnium");
        element $Ta(-73, -107, 0, -1, "", "Anti-Tantalum");
        element $W(-74, -109, 0, -1, "", "Anti-Wolframium");
        element $Re(-75, -111, 0, -1, "", "Anti-Rhenium");
        element $Os(-76, -114, 0, -1, "", "Anti-Osmium");
        element $Ir(-77, -115, 0, -1, "", "Anti-Iridium");
        element $Pt(-78, -117, 0, -1, "", "Anti-Platinum");
        element $Au(-79, -117, 0, -1, "", "Anti-Gold");
        element $Hg(-80, -120, 0, -1, "", "Anti-Mercury");
        element $Tl(-81, -123, 0, -1, "", "Anti-Thallium");
        element $Pb(-82, -125, 0, -1, "", "Anti-Lead");
        element $Bi(-83, -125, 0, -1, "", "Anti-Bismuth");
        element $Po(-84, -124, 0, -1, "", "Anti-Polonium");
        element $At(-85, -124, 0, -1, "", "Anti-Astatine");
        element $Rn(-86, -134, 0, -1, "", "Anti-Radon");
        element $Fr(-87, -134, 0, -1, "", "Anti-Francium");
        element $Ra(-88, -136, 0, -1, "", "Anti-Radium");
        element $Ac(-89, -136, 0, -1, "", "Anti-Actinium");
        element $Th(-90, -140, 0, -1, "", "Anti-Thorium");
        element $Pa(-91, -138, 0, -1, "", "Anti-Protactinium");
        element $U(-92, -146, 0, -1, "", "Anti-Uranium");
        element $U_235(-92, -143, 0, -1, "", "Anti-Uranium-235");
        element $Np(-93, -144, 0, -1, "", "Anti-Neptunium");
        element $Pu(-94, -152, 0, -1, "", "Anti-Plutonium");
        element $Pu_241(-94, -149, 0, -1, "", "Anti-Plutonium-241");
        element $Am(-95, -150, 0, -1, "", "Anti-Americum");
        element $Cm(-96, -153, 0, -1, "", "Anti-Curium");
        element $Bk(-97, -152, 0, -1, "", "Anti-Berkelium");
        element $Cf(-98, -153, 0, -1, "", "Anti-Californium");
        element $Es(-99, -153, 0, -1, "", "Anti-Einsteinium");
        element $Fm(-100, -157, 0, -1, "", "Anti-Fermium");
        element $Md(-101, -157, 0, -1, "", "Anti-Mendelevium");
        element $No(-102, -157, 0, -1, "", "Anti-Nobelium");
        element $Lr(-103, -159, 0, -1, "", "Anti-Lawrencium");
        element $Rf(-104, -161, 0, -1, "", "Anti-Rutherfordium");
        element $Db(-105, -163, 0, -1, "", "Anti-Dubnium");
        element $Sg(-106, -165, 0, -1, "", "Anti-Seaborgium");
        element $Bh(-107, -163, 0, -1, "", "Anti-Bohrium");
        element $Hs(-108, -169, 0, -1, "", "Anti-Hassium");
        element $Mt(-109, -167, 0, -1, "", "Anti-Meitnerium");
        element $Ds(-110, -171, 0, -1, "", "Anti-Darmstadtium");
        element $Rg(-111, -169, 0, -1, "", "Anti-Roentgenium");
        element $Cn(-112, -173, 0, -1, "", "Anti-Copernicium");
        element $Uut(-113, -171, 0, -1, "", "Anti-Ununtrium");
        element $Fl(-114, -175, 0, -1, "", "Anti-Flerovium");
        element $Uup(-115, -173, 0, -1, "", "Anti-Ununpentium");
        element $Lv(-116, -177, 0, -1, "", "Anti-Livermorium");
        element $Uus(-117, -177, 0, -1, "", "Anti-Ununseptium");
        element $Uuo(-118, -176, 0, -1, "", "Anti-Ununoctium");
        element $Ma(0, 0, -100, -1, "", "Anti-Magic");
        element $Nt(0, -100000, 0, -1, "", "Anti-Neutronium");
    }
    struct material {
        struct stack {
            stack(material & aMaterial, int aNum) {}
        };
        material(int aMetaItemSubID, textures aIconSet, int aToolQuality, bool aUnificatable) {}

        material(material & aMaterialInto, bool aReRegisterIntoThis) {}

        material(int aMetaItemSubID, textures aIconSet, int aToolQuality, int aTypes, int aR, int aG, int aB, int aA,
                 string aLocalName, int aFuelType, int aFuelPower, int aAmplificationValue, int aUUMEnergy,
                 int aMeltingPoint, int aBlastFurnaceTemp, bool aBlastFurnaceRequired, bool aTransparent,
                 int aOreValue, int aDensityMultiplier, int aDensityDivider, dye & aColor) :
                 material(aMetaItemSubID, aIconSet, aToolQuality, true) {
            fdump << setfill(' ') << setw(21) << aLocalName << ": ";
            fdump << hex << uppercase << setfill('0') << "#";
            fdump << setw(2) << aR << setw(2) << aG << setw(2) << aB << setw(2) << 255 - aA << endl;
        }

        /**
        * @param aElement The Element Enum represented by this Material
        */
        material(int aMetaItemSubID, textures aIconSet, int aToolQuality, int aTypes, int aR, int aG, int aB, int aA,
                 string aLocalName, int aFuelType, int aFuelPower, int aAmplificationValue, int aUUMEnergy,
                 int aMeltingPoint, int aBlastFurnaceTemp, bool aBlastFurnaceRequired, bool aTransparent,
                 int aOreValue, int aDensityMultiplier, int aDensityDivider, dye & aColor, element & aElement) :
                 material(aMetaItemSubID, aIconSet, aToolQuality, aTypes, aR, aG, aB, aA, aLocalName, aFuelType,
                 aFuelPower, aAmplificationValue, aUUMEnergy, aMeltingPoint, aBlastFurnaceTemp, aBlastFurnaceRequired,
                 aTransparent, aOreValue, aDensityMultiplier, aDensityDivider, aColor) {}

        material(int aMetaItemSubID, textures aIconSet, int aToolQuality, int aTypes, int aR, int aG, int aB, int aA,
                 string aLocalName, int aFuelType, int aFuelPower, int aAmplificationValue, int aUUMEnergy,
                 int aMeltingPoint, int aBlastFurnaceTemp, bool aBlastFurnaceRequired, bool aTransparent,
                 int aOreValue, int aDensityMultiplier, int aDensityDivider, dye & aColor, int aExtraData,
                 vector<stack> aMaterialList) :
                 material(aMetaItemSubID, aIconSet, aToolQuality, aTypes, aR, aG, aB, aA, aLocalName, aFuelType,
                 aFuelPower, aAmplificationValue, aUUMEnergy, aMeltingPoint, aBlastFurnaceTemp, aBlastFurnaceRequired,
                 aTransparent, aOreValue, aDensityMultiplier, aDensityDivider, aColor) {}
    };
    namespace materials {
        /**
        * Direct Elements
        */
        material Aluminium(19, textures::SET_DULL, 2, 1 | 2 | 8 | 64 | 128, 128, 200, 240, 0, "Aluminium", 0, 0, 0, 0, 1700, 1700, true, false, 3, 1, 1, dyes::LightBlue, elements::Al);
        material Americium(103, textures::SET_METALLIC, 3, 1 | 2 | 8, 200, 200, 200, 0, "Americium", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::LightGray, elements::Am);
        material Antimony(58, textures::SET_SHINY, 2, 1 | 2 | 8, 220, 220, 240, 0, "Antimony", 0, 0, 0, 0, 0, 0, false, false, 2, 1, 1, dyes::LightGray, elements::Sb);
        material Arsenic(39, textures::SET_FLUID, 2, 16 | 32, 255, 255, 255, 0, "Arsenic", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Orange, elements::As);
        material Barium(63, textures::SET_METALLIC, 2, 1 | 8 | 16 | 32, 255, 255, 255, 0, "Barium", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL, elements::Ba);
        material Beryllium(8, textures::SET_METALLIC, 2, 1 | 2 | 8 | 16 | 32 | 64, 100, 180, 100, 0, "Beryllium", 0, 0, 0, 0, 0, 0, false, false, 6, 1, 1, dyes::Green, elements::Be);
        material Boron(9, textures::SET_DULL, 2, 1 | 8 | 16 | 32, 250, 250, 250, 0, "Boron", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::White, elements::B);
        material Caesium(62, textures::SET_METALLIC, 2, 1 | 2 | 8 | 16 | 32, 255, 255, 255, 0, "Caesium", 0, 0, 0, 0, 0, 0, false, false, 4, 1, 1, dyes::_NULL, elements::Cs);
        material Calcium(26, textures::SET_METALLIC, 2, 1 | 16 | 32, 255, 245, 245, 0, "Calcium", 0, 0, 0, 0, 0, 0, false, false, 4, 1, 1, dyes::Pink, elements::Ca);
        material Carbon(10, textures::SET_DULL, 2, 1 | 16 | 32 | 64 | 128, 20, 20, 20, 0, "Carbon", 0, 0, 0, 0, 0, 0, false, false, 2, 1, 1, dyes::Black, elements::C);
        material Cadmium(55, textures::SET_SHINY, 2, 1 | 8 | 16 | 32, 50, 50, 60, 0, "Cadmium", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Gray, elements::Cd);
        material Cerium(65, textures::SET_METALLIC, 2, 1 | 2 | 8 | 16 | 32, 255, 255, 255, 0, "Cerium", 0, 0, 0, 0, 1068, 1068, true, false, 4, 1, 1, dyes::_NULL, elements::Ce);
        material Chlorine(23, textures::SET_FLUID, 2, 16 | 32, 255, 255, 255, 0, "Chlorine", 0, 0, 0, 0, 0, 0, false, false, 2, 1, 1, dyes::Cyan, elements::Cl);
        material Chrome(30, textures::SET_SHINY, 3, 1 | 2 | 8 | 64 | 128, 255, 230, 230, 0, "Chrome", 0, 0, 0, 0, 1700, 1700, true, false, 5, 1, 1, dyes::Pink, elements::Cr);
        material Cobalt(33, textures::SET_METALLIC, 3, 1 | 2 | 8 | 64, 80, 80, 250, 0, "Cobalt", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Blue, elements::Co);
        material Copper(35, textures::SET_SHINY, 1, 1 | 2 | 8 | 128, 255, 100, 0, 0, "Copper", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Orange, elements::Cu);
        material Deuterium(2, textures::SET_FLUID, 2, 16 | 32, 255, 255, 0, 240, "Deuterium", 0, 0, 0, 0, 0, 0, false, true, 10, 1, 1, dyes::Yellow, elements::D);
        material Dysprosium(73, textures::SET_METALLIC, 2, 1 | 2 | 8 | 16 | 32, 255, 255, 255, 0, "Dysprosium", 0, 0, 0, 0, 1680, 1680, true, false, 4, 1, 1, dyes::_NULL, elements::Dy);
        material Empty(0, textures::SET_EMPTY, 2, 16 | 32, 255, 255, 255, 255, "Empty", 0, 0, 0, 0, 0, 0, false, true, 1, 1, 1, dyes::_NULL, elements::_NULL);
        material Erbium(75, textures::SET_METALLIC, 2, 1 | 2 | 8 | 16 | 32, 255, 255, 255, 0, "Erbium", 0, 0, 0, 0, 1802, 1802, true, false, 4, 1, 1, dyes::_NULL, elements::Er);
        material Europium(70, textures::SET_METALLIC, 2, 1 | 2 | 8 | 16 | 32, 255, 255, 255, 0, "Europium", 0, 0, 0, 0, 1099, 1099, true, false, 4, 1, 1, dyes::_NULL, elements::Eu);
        material Fluorine(14, textures::SET_FLUID, 2, 16 | 32, 255, 255, 255, 127, "Fluorine", 0, 0, 0, 0, 0, 0, false, true, 2, 1, 1, dyes::Green, elements::F);
        material Gadolinium(71, textures::SET_METALLIC, 2, 1 | 2 | 8 | 16 | 32, 255, 255, 255, 0, "Gadolinium", 0, 0, 0, 0, 1585, 1585, true, false, 4, 1, 1, dyes::_NULL, elements::Gd);
        material Gold(86, textures::SET_SHINY, 2, 1 | 2 | 8 | 64 | 128, 255, 255, 30, 0, "Gold", 0, 0, 0, 0, 0, 0, false, false, 4, 1, 1, dyes::Yellow, elements::Au);
        material Holmium(74, textures::SET_METALLIC, 2, 1 | 2 | 8 | 16 | 32, 255, 255, 255, 0, "Holmium", 0, 0, 0, 0, 1734, 1734, true, false, 4, 1, 1, dyes::_NULL, elements::Ho);
        material Hydrogen(1, textures::SET_FLUID, 2, 16 | 32, 0, 0, 255, 240, "Hydrogen", 1, 15, 0, 0, 0, 0, false, true, 2, 1, 1, dyes::Blue, elements::H);
        material Helium(4, textures::SET_FLUID, 2, 16 | 32, 255, 255, 0, 240, "Helium", 0, 0, 0, 0, 0, 0, false, true, 5, 1, 1, dyes::Yellow, elements::He);
        material Helium_3(5, textures::SET_FLUID, 2, 16 | 32, 255, 255, 0, 240, "Helium-3", 0, 0, 0, 0, 0, 0, false, true, 10, 1, 1, dyes::Yellow, elements::He_3);
        material Indium(56, textures::SET_METALLIC, 2, 1 | 2 | 8, 255, 255, 255, 0, "Indium", 0, 0, 0, 0, 0, 0, false, false, 4, 1, 1, dyes::Gray, elements::In);
        material Iridium(84, textures::SET_DULL, 4, 1 | 2 | 8 | 64 | 128, 240, 240, 245, 0, "Iridium", 0, 0, 0, 0, 0, 0, false, false, 10, 1, 1, dyes::White, elements::Ir);
        material Iron(32, textures::SET_METALLIC, 2, 1 | 2 | 8 | 64 | 128, 200, 200, 200, 0, "Iron", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::LightGray, elements::Fe);
        material Lanthanum(64, textures::SET_METALLIC, 2, 1 | 2 | 8 | 16 | 32, 255, 255, 255, 0, "Lanthanum", 0, 0, 0, 0, 1193, 1193, true, false, 4, 1, 1, dyes::_NULL, elements::La);
        material Lead(89, textures::SET_DULL, 1, 1 | 2 | 8 | 64 | 128, 140, 100, 140, 0, "Lead", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Purple, elements::Pb);
        material Lithium(6, textures::SET_DULL, 2, 1 | 8 | 16 | 32, 225, 220, 255, 0, "Lithium", 3, 60, 0, 0, 0, 0, false, false, 4, 1, 1, dyes::LightBlue, elements::Li);
        material Lutetium(78, textures::SET_METALLIC, 2, 1 | 2 | 8 | 16 | 32, 255, 255, 255, 0, "Lutetium", 0, 0, 0, 0, 1925, 1925, true, false, 4, 1, 1, dyes::_NULL, elements::Lu);
        material Magic(-128, textures::SET_SHINY, 5, 1 | 2 | 4 | 8 | 16 | 32 | 64 | 128, 100, 0, 200, 0, "Magic", 5, 32, 0, 0, 0, 0, false, false, 7, 1, 1, dyes::Purple, elements::Ma);
        material Magnesium(18, textures::SET_METALLIC, 2, 1 | 2 | 8 | 16 | 32, 255, 200, 200, 0, "Magnesium", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Pink, elements::Mg);
        material Manganese(31, textures::SET_DULL, 3, 1 | 2 | 8 | 64, 250, 250, 250, 0, "Manganese", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::White, elements::Mn);
        material Mercury(87, textures::SET_SHINY, 0, 16 | 32, 255, 220, 220, 0, "Mercury", 5, 32, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::LightGray, elements::Hg);
        material Niobium(47, textures::SET_METALLIC, 2, 1 | 2 | 8, 255, 255, 255, 0, "Niobium", 0, 0, 0, 0, 0, 0, false, false, 4, 1, 1, dyes::_NULL, elements::Nb);
        material Molybdenum(48, textures::SET_SHINY, 2, 1 | 2 | 8 | 64, 180, 180, 220, 0, "Molybdenum", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Blue, elements::Mo);
        material Neodymium(67, textures::SET_METALLIC, 2, 1 | 2 | 8 | 16 | 32, 255, 255, 255, 0, "Neodymium", 0, 0, 0, 0, 1297, 1297, true, false, 4, 1, 1, dyes::_NULL, elements::Nd);
        material Neutronium(129, textures::SET_DULL, 2, 1 | 2 | 8 | 64 | 128, 250, 250, 250, 0, "Neutronium", 0, 0, 0, 0, 0, 0, false, false, 20, 1, 1, dyes::White, elements::Nt);
        material Nickel(34, textures::SET_METALLIC, 2, 1 | 2 | 8 | 64 | 128, 200, 200, 250, 0, "Nickel", 0, 0, 0, 0, 0, 0, false, false, 4, 1, 1, dyes::LightBlue, elements::Ni);
        material Nitrogen(12, textures::SET_FLUID, 2, 16 | 32, 0, 150, 200, 240, "Nitrogen", 0, 0, 0, 0, 0, 0, false, true, 2, 1, 1, dyes::Cyan, elements::N);
        material Osmium(83, textures::SET_METALLIC, 4, 1 | 2 | 8 | 64 | 128, 50, 50, 255, 0, "Osmium", 0, 0, 0, 0, 0, 0, false, false, 10, 1, 1, dyes::Blue, elements::Os);
        material Oxygen(13, textures::SET_FLUID, 2, 16 | 32, 0, 100, 200, 240, "Oxygen", 0, 0, 0, 0, 0, 0, false, true, 1, 1, 1, dyes::White, elements::O);
        material Palladium(52, textures::SET_SHINY, 2, 1 | 2 | 8 | 64 | 128, 128, 128, 128, 0, "Palladium", 0, 0, 0, 0, 0, 0, false, false, 4, 1, 1, dyes::Gray, elements::Pd);
        material Phosphor(21, textures::SET_DULL, 2, 1 | 8 | 16 | 32, 255, 255, 0, 0, "Phosphor", 0, 0, 0, 0, 0, 0, false, false, 2, 1, 1, dyes::Yellow, elements::P);
        material Platinum(85, textures::SET_SHINY, 2, 1 | 2 | 8 | 64 | 128, 255, 255, 200, 0, "Platinum", 0, 0, 0, 0, 0, 0, false, false, 6, 1, 1, dyes::Orange, elements::Pt);
        material Plutonium(100, textures::SET_METALLIC, 3, 1 | 2 | 8 | 64, 240, 50, 50, 0, "Plutonium 244", 0, 0, 2000000, 0, 0, 0, false, false, 6, 1, 1, dyes::Lime, elements::Pu);
        material Plutonium241(101, textures::SET_SHINY, 3, 1 | 2 | 8 | 64, 250, 70, 70, 0, "Plutonium 241", 0, 0, 2000000, 0, 0, 0, false, false, 6, 1, 1, dyes::Lime, elements::Pu_241);
        material Potassium(25, textures::SET_METALLIC, 1, 1 | 16 | 32, 250, 250, 250, 0, "Potassium", 0, 0, 0, 0, 0, 0, false, false, 2, 1, 1, dyes::White, elements::K);
        material Praseodymium(66, textures::SET_METALLIC, 2, 1 | 2 | 8 | 16 | 32, 255, 255, 255, 0, "Praseodymium", 0, 0, 0, 0, 1208, 1208, true, false, 4, 1, 1, dyes::_NULL, elements::Pr);
        material Promethium(68, textures::SET_METALLIC, 2, 1 | 2 | 8 | 16 | 32, 255, 255, 255, 0, "Promethium", 0, 0, 0, 0, 1315, 1315, true, false, 4, 1, 1, dyes::_NULL, elements::Pm);
        material Rubidium(43, textures::SET_METALLIC, 2, 1 | 2 | 8, 240, 30, 30, 0, "Rubidium", 0, 0, 0, 0, 0, 0, false, false, 4, 1, 1, dyes::Red, elements::Rb);
        material Samarium(69, textures::SET_METALLIC, 2, 1 | 2 | 8 | 16 | 32, 255, 255, 255, 0, "Samarium", 0, 0, 0, 0, 1345, 1345, true, false, 4, 1, 1, dyes::_NULL, elements::Sm);
        material Scandium(27, textures::SET_METALLIC, 2, 1 | 2 | 8 | 16 | 32, 255, 255, 255, 0, "Scandium", 0, 0, 0, 0, 1814, 1814, true, false, 2, 1, 1, dyes::Yellow, elements::Sc);
        material Silicon(20, textures::SET_METALLIC, 2, 1 | 2 | 8 | 16 | 32, 60, 60, 80, 0, "Silicon", 0, 0, 0, 0, 1500, 1500, true, false, 1, 1, 1, dyes::Black, elements::Si);
        material Silver(54, textures::SET_SHINY, 2, 1 | 2 | 8 | 64 | 128, 220, 220, 255, 0, "Silver", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::LightGray, elements::Ag);
        material Sodium(17, textures::SET_METALLIC, 2, 1 | 16 | 32, 0, 0, 150, 0, "Sodium", 3, 30, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Blue, elements::Na);
        material Strontium(44, textures::SET_METALLIC, 2, 1 | 8, 200, 200, 200, 0, "Strontium", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::LightGray, elements::Sr);
        material Sulfur(22, textures::SET_DULL, 2, 1 | 8 | 16 | 32, 200, 200, 0, 0, "Sulfur", 0, 0, 0, 0, 0, 0, false, false, 2, 1, 1, dyes::Yellow, elements::S);
        material Tantalum(80, textures::SET_METALLIC, 2, 1 | 2 | 8, 255, 255, 255, 0, "Tantalum", 0, 0, 0, 0, 0, 0, false, false, 4, 1, 1, dyes::_NULL, elements::Ta);
        material Tellurium(59, textures::SET_METALLIC, 2, 1 | 2 | 8, 255, 255, 255, 0, "Tellurium", 0, 0, 0, 0, 0, 0, false, false, 4, 1, 1, dyes::Gray, elements::Te);
        material Terbium(72, textures::SET_METALLIC, 2, 1 | 2 | 8 | 16 | 32, 255, 255, 255, 0, "Terbium", 0, 0, 0, 0, 1629, 1629, true, false, 4, 1, 1, dyes::_NULL, elements::Tb);
        material Thorium(96, textures::SET_SHINY, 2, 1 | 2 | 8 | 64, 0, 30, 0, 0, "Thorium", 0, 0, 500000, 0, 0, 0, false, false, 4, 1, 1, dyes::Black, elements::Th);
        material Thulium(76, textures::SET_METALLIC, 2, 1 | 2 | 8 | 16 | 32, 255, 255, 255, 0, "Thulium", 0, 0, 0, 0, 1818, 1818, true, false, 4, 1, 1, dyes::_NULL, elements::Tm);
        material Tin(57, textures::SET_DULL, 1, 1 | 2 | 8 | 128, 220, 220, 220, 0, "Tin", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::White, elements::Sn);
        material Titanium(28, textures::SET_METALLIC, 3, 1 | 2 | 8 | 64 | 128, 220, 160, 240, 0, "Titanium", 0, 0, 0, 0, 1500, 1500, true, false, 5, 1, 1, dyes::Purple, elements::Ti);
        material Tritium(3, textures::SET_METALLIC, 2, 16 | 32, 255, 0, 0, 240, "Tritium", 0, 0, 0, 0, 0, 0, false, true, 10, 1, 1, dyes::Red, elements::T);
        material Tungsten(81, textures::SET_METALLIC, 3, 1 | 2 | 8 | 64 | 128, 50, 50, 50, 0, "Tungsten", 0, 0, 0, 0, 2500, 2500, true, false, 4, 1, 1, dyes::Black, elements::W);
        material Uranium(98, textures::SET_METALLIC, 3, 1 | 2 | 8 | 64, 50, 240, 50, 0, "Uranium 238", 0, 0, 1000000, 0, 0, 0, false, false, 4, 1, 1, dyes::Green, elements::U);
        material Uranium235(97, textures::SET_SHINY, 3, 1 | 2 | 8 | 64, 70, 250, 70, 0, "Uranium 235", 0, 0, 1000000, 0, 0, 0, false, false, 4, 1, 1, dyes::Green, elements::U_235);
        material Vanadium(29, textures::SET_METALLIC, 2, 1 | 2 | 8, 50, 50, 50, 0, "Vanadium", 0, 0, 0, 0, 0, 0, false, false, 2, 1, 1, dyes::Black, elements::V);
        material Ytterbium(77, textures::SET_METALLIC, 2, 1 | 2 | 8 | 16 | 32, 255, 255, 255, 0, "Ytterbium", 0, 0, 0, 0, 1097, 1097, true, false, 4, 1, 1, dyes::_NULL, elements::Yb);
        material Yttrium(45, textures::SET_METALLIC, 2, 1 | 2 | 8 | 16 | 32, 255, 255, 255, 0, "Yttrium", 0, 0, 0, 0, 1799, 1799, true, false, 4, 1, 1, dyes::_NULL, elements::Y);
        material Zinc(36, textures::SET_METALLIC, 1, 1 | 2 | 8, 250, 240, 240, 0, "Zinc", 0, 0, 0, 0, 0, 0, false, false, 2, 1, 1, dyes::White, elements::Zn);

        /**
        * The "Random Material" ones.
        */
        material Organic(-1, textures::SET_LEAF, 1, false);
        material Crystal(-1, textures::SET_SHINY, 3, false);
        material Quartz(-1, textures::SET_QUARTZ, 2, false);
        material Metal(-1, textures::SET_METALLIC, 2, false);
        material Cobblestone(-1, textures::SET_DULL, 1, false);

        /**
        * Unknown Material Components. Dead End Section.
        */
        material Adamantium(319, textures::SET_SHINY, 4, 1 | 2 | 8 | 64 | 128, 255, 255, 255, 0, "Adamantium", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::LightGray);
        material Adamite(-1, textures::SET_NONE, 3, 1 | 8, 255, 255, 255, 0, "Adamite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::LightGray);
        material Adluorite(-1, textures::SET_NONE, 2, 1 | 8, 255, 255, 255, 0, "Adluorite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Agate(-1, textures::SET_NONE, 2, 1, 255, 255, 255, 0, "Agate", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::_NULL);
        material Alduorite(-1, textures::SET_NONE, 2, 1 | 8, 255, 255, 255, 0, "Alduorite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Amber(514, textures::SET_RUBY, 3, 1 | 4 | 8, 255, 128, 0, 127, "Amber", 5, 3, 0, 0, 0, 0, false, true, 1, 1, 1, dyes::Orange);
        material Ammonium(-1, textures::SET_NONE, 2, 1, 255, 255, 255, 0, "Ammonium", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Amordrine(-1, textures::SET_NONE, 2, 1 | 2 | 8 | 64, 255, 255, 255, 0, "Amordrine", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Andesite(-1, textures::SET_NONE, 2, 1 | 8, 255, 255, 255, 0, "Andesite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Angmallen(-1, textures::SET_NONE, 2, 1 | 2 | 8 | 64, 255, 255, 255, 0, "Angmallen", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Ardite(-1, textures::SET_NONE, 2, 1 | 2 | 8 | 64, 255, 0, 0, 0, "Ardite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Yellow);
        material Aredrite(-1, textures::SET_NONE, 2, 1 | 2 | 8 | 64, 255, 0, 0, 0, "Aredrite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Yellow);
        material Atlarus(-1, textures::SET_NONE, 2, 1 | 2 | 8 | 64, 255, 255, 255, 0, "Atlarus", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Bitumen(-1, textures::SET_NONE, 2, 1 | 8, 255, 255, 255, 0, "Bitumen", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Black(-1, textures::SET_NONE, 2, 0, 0, 0, 0, 0, "Black", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Black);
        material Blizz(851, textures::SET_SHINY, 2, 1, 220, 233, 255, 0, "Blizz", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::_NULL);
        material Blueschist(852, textures::SET_DULL, 2, 1, 255, 255, 255, 0, "Blueschist", 0, 0, 0, 0, 0, 0, false, false, 0, 1, 1, dyes::LightBlue);
        material Bluestone(813, textures::SET_DULL, 2, 1, 255, 255, 255, 0, "Bluestone", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Blue);
        material Bloodstone(-1, textures::SET_NONE, 2, 1, 255, 255, 255, 0, "Bloodstone", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Red);
        material Blutonium(-1, textures::SET_SHINY, 2, 1 | 2 | 8, 0, 0, 255, 0, "Blutonium", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Blue);
        material Carmot(-1, textures::SET_NONE, 2, 1 | 2 | 8 | 64, 255, 255, 255, 0, "Carmot", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Celenegil(-1, textures::SET_NONE, 2, 1 | 2 | 8 | 64, 255, 255, 255, 0, "Celenegil", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material CertusQuartz(516, textures::SET_QUARTZ, 1, 1 | 4 | 8 | 64, 210, 210, 230, 0, "Certus Quartz", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::LightGray);
        material Ceruclase(-1, textures::SET_NONE, 2, 1 | 2 | 8, 255, 255, 255, 0, "Ceruclase", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Citrine(-1, textures::SET_NONE, 2, 1, 255, 255, 255, 0, "Citrine", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::_NULL);
        material CobaltHexahydrate(853, textures::SET_METALLIC, 2, 1 | 16, 80, 80, 250, 0, "Cobalt Hexahydrate", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Blue);
        material ConstructionFoam(854, textures::SET_DULL, 2, 1 | 16, 128, 128, 128, 0, "Construction Foam", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Gray);
        material Chalk(856, textures::SET_FINE, 2, 1, 250, 250, 250, 0, "Chalk", 0, 0, 0, 0, 0, 0, false, false, 0, 1, 1, dyes::White);
        material Chert(857, textures::SET_DULL, 2, 1, 255, 255, 255, 0, "Chert", 0, 0, 0, 0, 0, 0, false, false, 0, 1, 1, dyes::_NULL);
        material Chimerite(-1, textures::SET_NONE, 2, 1, 255, 255, 255, 0, "Chimerite", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::_NULL);
        material Coral(-1, textures::SET_NONE, 1, 1, 255, 128, 255, 0, "Coral", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::_NULL);
        material CrudeOil(858, textures::SET_DULL, 2, 1, 10, 10, 10, 0, "Crude Oil", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Black);
        material Chrysocolla(-1, textures::SET_NONE, 2, 1, 255, 255, 255, 0, "Chrysocolla", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::_NULL);
        material CrystalFlux(517, textures::SET_QUARTZ, 3, 1 | 4, 100, 50, 100, 0, "Flux Crystal", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Cyanite(-1, textures::SET_NONE, 2, 1, 255, 255, 255, 0, "Cyanite", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Cyan);
        material Dacite(859, textures::SET_DULL, 2, 1, 255, 255, 255, 0, "Dacite", 0, 0, 0, 0, 0, 0, false, false, 0, 1, 1, dyes::LightGray);
        material DarkIron(342, textures::SET_DULL, 3, 1 | 2 | 8 | 64, 55, 40, 60, 0, "Dark Iron", 0, 0, 0, 0, 0, 0, false, false, 5, 1, 1, dyes::Purple);
        material DarkStone(-1, textures::SET_NONE, 2, 1, 255, 255, 255, 0, "Dark Stone", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Black);
        material Demonite(-1, textures::SET_NONE, 2, 1, 255, 255, 255, 0, "Demonite", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Red);
        material Desh(884, textures::SET_DULL, 2, 1 | 2 | 8, 40, 40, 40, 0, "Desh", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Black);
        material Desichalkos(-1, textures::SET_NONE, 3, 1 | 2 | 8 | 64, 255, 255, 255, 0, "Desichalkos", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Dilithium(515, textures::SET_DIAMOND, 1, 1 | 4 | 8 | 16, 255, 250, 250, 127, "Dilithium", 0, 0, 0, 0, 0, 0, false, true, 1, 1, 1, dyes::White);
        material Draconic(-1, textures::SET_NONE, 2, 1, 255, 255, 255, 0, "Draconic", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Red);
        material Duranium(328, textures::SET_METALLIC, 4, 1 | 2 | 64, 255, 255, 255, 0, "Duranium", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::LightGray);
        material Eclogite(860, textures::SET_DULL, 2, 1, 255, 255, 255, 0, "Eclogite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material ElectrumFlux(320, textures::SET_SHINY, 3, 1 | 2 | 64, 255, 255, 120, 0, "Fluxed Electrum", 0, 0, 0, 0, 3000, 3000, true, false, 1, 1, 1, dyes::Yellow);
        material Emery(861, textures::SET_DULL, 2, 1 | 8, 255, 255, 255, 0, "Emery", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Enderium(321, textures::SET_DULL, 3, 1 | 2 | 64, 89, 145, 135, 0, "Enderium", 0, 0, 0, 0, 3000, 3000, true, false, 1, 1, 1, dyes::Green);
        material Energized(-1, textures::SET_NONE, 2, 0, 255, 255, 255, 0, "Energized", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Epidote(862, textures::SET_DULL, 2, 1, 255, 255, 255, 0, "Epidote", 0, 0, 0, 0, 0, 0, false, false, 0, 1, 1, dyes::_NULL);
        material Eximite(-1, textures::SET_NONE, 2, 1 | 2 | 8 | 64, 255, 255, 255, 0, "Eximite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material FieryBlood(-1, textures::SET_NONE, 2, 1 | 2 | 64, 255, 255, 255, 0, "Fiery Blood", 5, 2048, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Red);
        material Firestone(-1, textures::SET_NONE, 2, 0, 255, 255, 255, 0, "Firestone", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Orange);
        material Fluorite(-1, textures::SET_NONE, 2, 1 | 8, 255, 255, 255, 0, "Fluorite", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Green);
        material FoolsRuby(512, textures::SET_RUBY, 2, 1 | 4 | 8, 255, 100, 100, 127, "Ruby", 0, 0, 0, 0, 0, 0, false, true, 3, 1, 1, dyes::Red);
        material Force(521, textures::SET_DIAMOND, 3, 1 | 2 | 4 | 8 | 64 | 128, 255, 255, 0, 0, "Force", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Yellow);
        material Forcicium(518, textures::SET_DIAMOND, 1, 1 | 4 | 8 | 16, 50, 50, 70, 0, "Forcicium", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Green);
        material Forcillium(519, textures::SET_DIAMOND, 1, 1 | 4 | 8 | 16, 50, 50, 70, 0, "Forcillium", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Green);
        material Gabbro(863, textures::SET_DULL, 1, 1, 255, 255, 255, 0, "Gabbro", 0, 0, 0, 0, 0, 0, false, false, 0, 1, 1, dyes::_NULL);
        material Glowstone(811, textures::SET_SHINY, 1, 1 | 16, 255, 255, 0, 0, "Glowstone", 0, 0, 25000, 0, 0, 0, false, false, 1, 1, 1, dyes::Yellow);
        material Gneiss(864, textures::SET_DULL, 1, 1, 255, 255, 255, 0, "Gneiss", 0, 0, 0, 0, 0, 0, false, false, 0, 1, 1, dyes::_NULL);
        material Graphite(865, textures::SET_DULL, 2, 1 | 8 | 64 | 128, 128, 128, 128, 0, "Graphite", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Gray);
        material Graphene(819, textures::SET_DULL, 1, 1 | 64 | 128, 128, 128, 128, 0, "Graphene", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Gray);
        material Greenschist(866, textures::SET_DULL, 1, 1, 255, 255, 255, 0, "Green Schist", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Green);
        material Greenstone(867, textures::SET_DULL, 1, 1, 255, 255, 255, 0, "Greenstone", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Green);
        material Greywacke(868, textures::SET_DULL, 1, 1, 255, 255, 255, 0, "Greywacke", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Gray);
        material Haderoth(-1, textures::SET_NONE, 2, 1 | 2 | 8 | 64, 255, 255, 255, 0, "Haderoth", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Hematite(-1, textures::SET_NONE, 2, 1 | 2 | 8, 255, 255, 255, 0, "Hematite", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::_NULL);
        material Hepatizon(-1, textures::SET_NONE, 2, 1 | 2 | 8 | 64, 255, 255, 255, 0, "Hepatizon", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material HSLA(322, textures::SET_METALLIC, 3, 1 | 2 | 64 | 128, 128, 128, 128, 0, "HSLA Steel", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::_NULL);
        material Ignatius(-1, textures::SET_NONE, 2, 1, 255, 255, 255, 0, "Ignatius", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Infernal(-1, textures::SET_NONE, 2, 0, 255, 255, 255, 0, "Infernal", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Infuscolium(-1, textures::SET_NONE, 2, 1 | 2 | 8 | 64, 255, 255, 255, 0, "Infuscolium", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::_NULL);
        material InfusedGold(323, textures::SET_SHINY, 3, 1 | 2 | 8 | 64 | 128, 255, 200, 60, 0, "Infused Gold", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Yellow);
        material InfusedAir(-1, textures::SET_NONE, 2, 0, 255, 255, 255, 0, "Infused Air", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Yellow);
        material InfusedFire(-1, textures::SET_NONE, 2, 0, 255, 255, 255, 0, "Infused Fire", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Red);
        material InfusedEarth(-1, textures::SET_NONE, 2, 0, 255, 255, 255, 0, "Infused Earth", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Green);
        material InfusedWater(-1, textures::SET_NONE, 2, 0, 255, 255, 255, 0, "Infused Water", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Blue);
        material InfusedVis(-1, textures::SET_NONE, 2, 0, 255, 255, 255, 0, "Infused Vis", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Purple);
        material InfusedDull(-1, textures::SET_NONE, 2, 0, 255, 255, 255, 0, "Infused Dull", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::LightGray);
        material InfusedEntropy(-1, textures::SET_NONE, 2, 0, 255, 255, 255, 0, "Infused Entropy", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::_NULL);
        material InfusedOrder(-1, textures::SET_NONE, 2, 0, 255, 255, 255, 0, "Infused Order", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::_NULL);
        material Inolashite(-1, textures::SET_NONE, 2, 1 | 2 | 8 | 64, 255, 255, 255, 0, "Inolashite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Invisium(-1, textures::SET_NONE, 2, 1, 255, 255, 255, 0, "Invisium", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::_NULL);
        material Jade(537, textures::SET_SHINY, 2, 1 | 8, 0, 100, 0, 0, "Jade", 0, 0, 0, 0, 0, 0, false, false, 5, 1, 1, dyes::Green);
        material Jasper(511, textures::SET_EMERALD, 2, 1 | 4 | 8, 200, 80, 80, 100, "Jasper", 0, 0, 0, 0, 0, 0, false, true, 3, 1, 1, dyes::Red);
        material Kalendrite(-1, textures::SET_NONE, 1, 1, 255, 255, 255, 0, "Kalendrite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Komatiite(869, textures::SET_DULL, 1, 1, 255, 255, 255, 0, "Komatiite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Yellow);
        material Lava(700, textures::SET_FLUID, 1, 16, 255, 64, 0, 0, "Lava", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Orange);
        material Lemurite(-1, textures::SET_NONE, 2, 1, 255, 255, 255, 0, "Lemurite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Limestone(-1, textures::SET_NONE, 1, 1, 255, 255, 255, 0, "Limestone", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Lodestone(-1, textures::SET_NONE, 1, 1 | 8, 255, 255, 255, 0, "Lodestone", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Luminite(-1, textures::SET_NONE, 1, 1 | 8, 250, 250, 250, 0, "Luminite", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::White);
        material Magma(-1, textures::SET_NONE, 1, 0, 255, 64, 0, 0, "Magma", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Orange);
        material Mawsitsit(-1, textures::SET_NONE, 1, 1, 255, 255, 255, 0, "Mawsitsit", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::_NULL);
        material Mercassium(-1, textures::SET_NONE, 1, 1 | 2 | 8 | 64, 255, 255, 255, 0, "Mercassium", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material MeteoricIron(340, textures::SET_METALLIC, 2, 1 | 2 | 8 | 64, 100, 50, 80, 0, "Meteoric Iron", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Gray);
        material MeteoricSteel(341, textures::SET_METALLIC, 3, 1 | 2 | 64, 50, 25, 40, 0, "Meteoric Steel", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Gray);
        material Meteorite(-1, textures::SET_NONE, 1, 1 | 8, 80, 35, 60, 0, "Meteorite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Purple);
        material Meutoite(-1, textures::SET_NONE, 1, 1 | 8, 255, 255, 255, 0, "Meutoite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Migmatite(872, textures::SET_DULL, 1, 1, 255, 255, 255, 0, "Migmatite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Mimichite(-1, textures::SET_GEM_VERTICAL, 1, 1 | 4 | 8, 255, 255, 255, 0, "Mimichite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Monazite(520, textures::SET_DIAMOND, 1, 1 | 4 | 8, 50, 70, 50, 0, "Monazite", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Green);
        material Moonstone(-1, textures::SET_NONE, 1, 1 | 8, 255, 255, 255, 0, "Moonstone", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::White);
        material Naquadah(324, textures::SET_METALLIC, 4, 1 | 2 | 8 | 16 | 64, 50, 50, 50, 0, "Naquadah", 0, 0, 0, 0, 0, 0, false, false, 10, 1, 1, dyes::Black);
        material NaquadahAlloy(325, textures::SET_METALLIC, 5, 1 | 2 | 64 | 128, 40, 40, 40, 0, "Naquadah Alloy", 0, 0, 0, 0, 0, 0, false, false, 10, 1, 1, dyes::Black);
        material Nether(-1, textures::SET_NONE, 1, 0, 255, 255, 255, 0, "Nether", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::_NULL);
        material NetherBrick(814, textures::SET_DULL, 1, 1, 100, 0, 0, 0, "Nether Brick", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Red);
        material NetherQuartz(522, textures::SET_QUARTZ, 1, 1 | 4 | 8, 230, 210, 210, 0, "Nether Quartz", 0, 0, 0, 0, 0, 0, false, false, 2, 1, 1, dyes::White);
        material NetherStar(506, textures::SET_NETHERSTAR, 1, 1 | 4, 255, 255, 255, 0, "Nether Star", 5, 50000, 0, 0, 0, 0, false, false, 15, 1, 1, dyes::White);
        material Nikolite(812, textures::SET_SHINY, 1, 1 | 8, 60, 180, 200, 0, "Nikolite", 0, 0, 5000, 0, 0, 0, false, false, 3, 1, 1, dyes::Cyan);
        material ObsidianFlux(-1, textures::SET_DULL, 1, 1 | 2, 80, 50, 100, 0, "Fluxed Obsidian", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Purple);
        material Oilsands(878, textures::SET_NONE, 1, 1 | 8, 255, 255, 255, 0, "Oilsands", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Onyx(-1, textures::SET_NONE, 1, 1, 255, 255, 255, 0, "Onyx", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::_NULL);
        material Orichalcum(-1, textures::SET_NONE, 3, 1 | 2 | 8 | 64, 255, 255, 255, 0, "Orichalcum", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Osmonium(-1, textures::SET_NONE, 1, 1 | 2 | 8 | 64, 255, 255, 255, 0, "Osmonium", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Blue);
        material Oureclase(-1, textures::SET_NONE, 1, 1 | 2 | 8 | 64, 255, 255, 255, 0, "Oureclase", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Painite(-1, textures::SET_NONE, 1, 0, 255, 255, 255, 0, "Painite", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::_NULL);
        material Peanutwood(-1, textures::SET_NONE, 1, 0, 255, 255, 255, 0, "Peanut Wood", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::_NULL);
        material Petroleum(-1, textures::SET_NONE, 1, 1 | 8, 255, 255, 255, 0, "Petroleum", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Pewter(-1, textures::SET_NONE, 1, 0, 255, 255, 255, 0, "Pewter", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::_NULL);
        material Phoenixite(-1, textures::SET_NONE, 1, 1 | 2 | 8 | 64, 255, 255, 255, 0, "Phoenixite", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::_NULL);
        material Potash(-1, textures::SET_NONE, 1, 0, 255, 255, 255, 0, "Potash", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Prometheum(-1, textures::SET_NONE, 1, 1 | 2 | 8 | 64, 255, 255, 255, 0, "Prometheum", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Quartzite(523, textures::SET_QUARTZ, 1, 1 | 4 | 8, 210, 230, 210, 0, "Quartzite", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::White);
        material Quicklime(-1, textures::SET_NONE, 1, 1, 255, 255, 255, 0, "Quicklime", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Randomite(-1, textures::SET_NONE, 1, 1 | 8, 255, 255, 255, 0, "Randomite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material RefinedGlowstone(-326, textures::SET_METALLIC, 1, 1 | 2, 255, 255, 0, 0, "Refined Glowstone", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Yellow);
        material RefinedObsidian(-327, textures::SET_METALLIC, 1, 1 | 2, 80, 50, 100, 0, "Refined Obsidian", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Purple);
        material Rhyolite(875, textures::SET_DULL, 1, 1, 255, 255, 255, 0, "Rhyolite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Rubracium(-1, textures::SET_NONE, 1, 1 | 8, 255, 255, 255, 0, "Rubracium", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material RyuDragonRyder(-1, textures::SET_NONE, 1, 0, 255, 255, 255, 0, "Ryu Dragon Ryder", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Sand(-1, textures::SET_NONE, 1, 0, 255, 255, 255, 0, "Sand", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Yellow);
        material Sanguinite(-1, textures::SET_NONE, 1, 1 | 2 | 8, 255, 255, 255, 0, "Sanguinite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Siltstone(876, textures::SET_DULL, 1, 1, 255, 255, 255, 0, "Siltstone", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Soapstone(877, textures::SET_DULL, 1, 1, 95, 145, 95, 0, "Soapstone", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Spinel(-1, textures::SET_NONE, 1, 0, 255, 255, 255, 0, "Spinel", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::_NULL);
        material Starconium(-1, textures::SET_NONE, 1, 1 | 2 | 8, 255, 255, 255, 0, "Starconium", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::_NULL);
        material Sugilite(-1, textures::SET_NONE, 1, 1, 255, 255, 255, 0, "Sugilite", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::_NULL);
        material Sunstone(-1, textures::SET_NONE, 1, 1 | 8, 255, 255, 255, 0, "Sunstone", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Yellow);
        material Tar(-1, textures::SET_NONE, 1, 0, 10, 10, 10, 0, "Tar", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Black);
        material Tartarite(-1, textures::SET_NONE, 1, 1 | 2 | 8, 255, 255, 255, 0, "Tartarite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Tapazite(-1, textures::SET_NONE, 1, 1, 255, 255, 255, 0, "Tapazite", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Green);
        material Thyrium(-1, textures::SET_NONE, 1, 1 | 2 | 8, 255, 255, 255, 0, "Thyrium", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::_NULL);
        material Tourmaline(-1, textures::SET_NONE, 1, 1, 255, 255, 255, 0, "Tourmaline", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::_NULL);
        material Tritanium(329, textures::SET_METALLIC, 1, 1 | 2 | 64, 255, 255, 255, 0, "Tritanium", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::White);
        material Turquoise(-1, textures::SET_NONE, 1, 1, 255, 255, 255, 0, "Turquoise", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::_NULL);
        material UUMatter(703, textures::SET_FLUID, 1, 16, 128, 0, 196, 0, "UUMatter", 0, 0, 0, 0, 0, 0, false, false, 10, 1, 1, dyes::Pink);
        material Void(-1, textures::SET_NONE, 1, 0, 255, 255, 255, 200, "Void", 0, 0, 0, 0, 0, 0, false, true, 1, 1, 1, dyes::_NULL);
        material Voidstone(-1, textures::SET_NONE, 1, 0, 255, 255, 255, 200, "Voidstone", 0, 0, 0, 0, 0, 0, false, true, 1, 1, 1, dyes::_NULL);
        material Vulcanite(-1, textures::SET_NONE, 2, 1 | 2 | 8 | 64, 255, 255, 255, 0, "Vulcanite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Vyroxeres(-1, textures::SET_NONE, 2, 1 | 2 | 8 | 64, 255, 255, 255, 0, "Vyroxeres", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL);
        material Wimalite(-1, textures::SET_NONE, 2, 8, 255, 255, 255, 0, "Wimalite", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Yellow);
        material Yellorite(-1, textures::SET_NONE, 2, 8, 255, 255, 255, 0, "Yellorite", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Yellow);
        material Yellorium(-1, textures::SET_NONE, 2, 1 | 2, 255, 255, 255, 0, "Yellorium", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Yellow);
        material Zectium(-1, textures::SET_NONE, 2, 1 | 2 | 8, 255, 255, 255, 0, "Zectium", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Black);

        /**
        * Not possible to determine exact Components
        */
        material Advanced(-1, textures::SET_NONE, 0, 0, 255, 255, 255, 0, "Advanced", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::LightGray);
        material Basic(-1, textures::SET_NONE, 0, 0, 255, 255, 255, 0, "Basic", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::LightGray);
        material Antimatter(-1, textures::SET_NONE, 0, 0, 255, 255, 255, 0, "Antimatter", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Pink);
        material BioFuel(705, textures::SET_FLUID, 0, 16, 255, 128, 0, 0, "Biofuel", 0, 6, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Orange);
        material Biomass(704, textures::SET_FLUID, 0, 16, 0, 255, 0, 0, "Biomass", 3, 8, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Green);
        material Chocolate(886, textures::SET_FINE, 0, 1, 190, 95, 0, 0, "Chocolate", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Brown);
        material Cluster(-1, textures::SET_NONE, 0, 0, 255, 255, 255, 127, "Cluster", 0, 0, 0, 0, 0, 0, false, true, 1, 1, 1, dyes::White);
        material CoalFuel(710, textures::SET_FLUID, 0, 16, 50, 50, 70, 0, "Coalfuel", 0, 16, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Black);
        material Cocoa(887, textures::SET_FINE, 0, 1, 190, 95, 0, 0, "Cocoa", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Brown);
        material Coffee(888, textures::SET_FINE, 0, 1, 150, 75, 0, 0, "Coffee", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Brown);
        material Creosote(712, textures::SET_FLUID, 0, 16, 128, 64, 0, 0, "Creosote", 3, 3, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Brown);
        material Data(-1, textures::SET_NONE, 0, 0, 255, 255, 255, 0, "Data", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::LightGray);
        material Elite(-1, textures::SET_NONE, 0, 0, 255, 255, 255, 0, "Elite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::LightGray);
        material Ethanol(706, textures::SET_FLUID, 0, 16, 255, 128, 0, 0, "Ethanol", 0, 128, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Purple);
        material Fuel(708, textures::SET_FLUID, 0, 16, 255, 255, 0, 0, "Diesel", 0, 128, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Yellow);
        material Good(-1, textures::SET_NONE, 0, 0, 255, 255, 255, 0, "Good", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::LightGray);
        material Gunpowder(800, textures::SET_DULL, 0, 1, 128, 128, 128, 0, "Gunpowder", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Gray);
        material Infinite(-1, textures::SET_NONE, 0, 0, 255, 255, 255, 0, "Infinite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::LightGray);
        material LimePure(-1, textures::SET_NONE, 0, 0, 255, 255, 255, 0, "Pure Lime", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Lime);
        material Master(-1, textures::SET_NONE, 0, 0, 255, 255, 255, 0, "Master", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::LightGray);
        material Meat(-1, textures::SET_NONE, 0, 0, 255, 255, 255, 0, "Meat", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Pink);
        material MeatRaw(-1, textures::SET_NONE, 0, 0, 255, 255, 255, 0, "Raw Meat", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Pink);
        material MeatCooked(-1, textures::SET_NONE, 0, 0, 255, 255, 255, 0, "Cooked Meat", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Pink);
        material Milk(885, textures::SET_FINE, 0, 1 | 16, 254, 254, 254, 0, "Milk", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::White);
        material Mud(-1, textures::SET_NONE, 0, 0, 255, 255, 255, 0, "Mud", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Brown);
        material Oil(707, textures::SET_FLUID, 0, 16, 0, 0, 0, 0, "Oil", 3, 16, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Black);
        material Paper(879, textures::SET_PAPER, 0, 1, 250, 250, 250, 0, "Paper", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::White);
        material Peat(-1, textures::SET_NONE, 0, 0, 255, 255, 255, 0, "Peat", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Brown);
        material Primitive(-1, textures::SET_NONE, 0, 0, 255, 255, 255, 0, "Primitive", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::LightGray);
        material Quantum(-1, textures::SET_NONE, 0, 0, 255, 255, 255, 0, "Quantum", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::White);
        material Red(-1, textures::SET_NONE, 0, 0, 255, 0, 0, 0, "Red", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Red);
        material Reinforced(-1, textures::SET_NONE, 0, 0, 255, 255, 255, 0, "Reinforced", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Gray);
        material SeedOil(713, textures::SET_FLUID, 0, 16, 196, 255, 0, 0, "Seed Oil", 3, 2, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Lime);
        material Stone(299, textures::SET_ROUGH, 1, 1 | 64 | 128, 205, 205, 205, 0, "Stone", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::LightGray);
        material TNT(-1, textures::SET_NONE, 0, 0, 255, 255, 255, 0, "TNT", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Red);
        material Ultimate(-1, textures::SET_NONE, 0, 0, 255, 255, 255, 0, "Ultimate", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::LightGray);
        material Unstable(-1, textures::SET_NONE, 4, 0, 255, 255, 255, 127, "Unstable", 0, 0, 0, 0, 0, 0, false, true, 1, 1, 1, dyes::White);
        material Unstableingot(-1, textures::SET_NONE, 4, 0, 255, 255, 255, 127, "Unstable", 0, 0, 0, 0, 0, 0, false, true, 1, 1, 1, dyes::White);
        material Wheat(881, textures::SET_POWDER, 0, 1, 255, 255, 196, 0, "Wheat", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Yellow);
        material Wood(809, textures::SET_WOOD, 0, 1 | 64 | 128, 200, 100, 0, 0, "Wood", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Brown);

        /**
        * TODO: This
        */
        material AluminiumBrass(-1, textures::SET_METALLIC, 2, 1 | 2 | 64, 255, 255, 255, 0, "Aluminium Brass", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Yellow);
        material Osmiridium(317, textures::SET_METALLIC, 4, 1 | 2 | 64 | 128, 100, 100, 255, 0, "Osmiridium", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::LightBlue);
        material Sunnarium(318, textures::SET_SHINY, 1, 1 | 2, 255, 255, 0, 0, "Sunnarium", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Yellow);
        material Endstone(808, textures::SET_DULL, 1, 1, 255, 255, 255, 0, "Endstone", 0, 0, 0, 0, 0, 0, false, false, 0, 1, 1, dyes::Yellow);
        material Netherrack(807, textures::SET_DULL, 0, 1, 200, 0, 0, 0, "Netherrack", 0, 0, 0, 0, 0, 0, false, false, 0, 1, 1, dyes::Red);
        material SoulSand(-1, textures::SET_DULL, 0, 1, 255, 255, 255, 0, "Soulsand", 0, 0, 0, 0, 0, 0, false, false, 0, 1, 1, dyes::Brown);

        /**
        * First Degree Compounds
        */
        material Almandine(820, textures::SET_ROUGH, 1, 1 | 8, 255, 0, 0, 0, "Almandine", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Red, 1, {material::stack(Aluminium, 2), material::stack(Iron, 3), material::stack(Silicon, 3), material::stack(Oxygen, 12)});
        material Andradite(821, textures::SET_ROUGH, 1, 1 | 8, 150, 120, 0, 0, "Andradite", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Yellow, 1, {material::stack(Calcium, 3), material::stack(Iron, 2), material::stack(Silicon, 3), material::stack(Oxygen, 12)});
        material AnnealedCopper(326, textures::SET_SHINY, 2, 1 | 2 | 128, 255, 120, 20, 0, "Annealed Copper", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Orange, 1, {material::stack(Copper, 1)});
        material Asbestos(946, textures::SET_DULL, 1, 1 | 8, 230, 230, 230, 0, "Asbestos", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::White, 1, {material::stack(Magnesium, 3), material::stack(Silicon, 2), material::stack(Hydrogen, 4), material::stack(Oxygen, 9)}); // Mg3Si2O5(OH)4
        material Ash(815, textures::SET_DULL, 1, 1, 150, 150, 150, 0, "Ashes", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::LightGray, 2, {material::stack(Carbon, 1)});
        material BandedIron(917, textures::SET_DULL, 2, 1 | 8, 145, 90, 90, 0, "Banded Iron", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Brown, 1, {material::stack(Iron, 2), material::stack(Oxygen, 3)});
        material BatteryAlloy(315, textures::SET_DULL, 1, 1 | 2, 156, 124, 160, 0, "Battery Alloy", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Purple, 2, {material::stack(Lead, 4), material::stack(Antimony, 1)});
        material Bauxite(822, textures::SET_DULL, 1, 1 | 8, 200, 100, 0, 0, "Bauxite", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Brown, 1, {material::stack(Titanium, 1), material::stack(Aluminium, 16), material::stack(Hydrogen, 10), material::stack(Oxygen, 12)});
        material BlueTopaz(513, textures::SET_GEM_HORIZONTAL, 3, 1 | 4 | 8 | 64, 0, 0, 255, 127, "Blue Topaz", 0, 0, 0, 0, 0, 0, false, true, 3, 1, 1, dyes::Blue, 1, {material::stack(Aluminium, 2), material::stack(Silicon, 1), material::stack(Fluorine, 2), material::stack(Hydrogen, 2), material::stack(Oxygen, 6)});
        material Bone(806, textures::SET_DULL, 1, 0, 250, 250, 250, 0, "Bone", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::White, 0, {material::stack(Calcium, 1)});
        material Brass(301, textures::SET_METALLIC, 1, 1 | 2 | 64 | 128, 255, 180, 0, 0, "Brass", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Yellow, 2, {material::stack(Zinc, 1), material::stack(Copper, 3)});
        material Bronze(300, textures::SET_METALLIC, 2, 1 | 2 | 64 | 128, 255, 128, 0, 0, "Bronze", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Orange, 2, {material::stack(Tin, 1), material::stack(Copper, 3)});
        material BrownLimonite(930, textures::SET_METALLIC, 1, 1 | 8, 200, 100, 0, 0, "Brown Limonite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Brown, 2, {material::stack(Iron, 1), material::stack(Hydrogen, 1), material::stack(Oxygen, 2)}); // FeO(OH)
        material Calcite(823, textures::SET_DULL, 1, 1, 250, 230, 220, 0, "Calcite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Orange, 1, {material::stack(Calcium, 1), material::stack(Carbon, 1), material::stack(Oxygen, 3)});
        material Cassiterite(824, textures::SET_METALLIC, 1, 8, 220, 220, 220, 0, "Cassiterite", 0, 0, 0, 0, 0, 0, false, false, 4, 3, 1, dyes::White, 1, {material::stack(Tin, 1), material::stack(Oxygen, 2)});
        material CassiteriteSand(937, textures::SET_SAND, 1, 8, 220, 220, 220, 0, "Cassiterite Sand", 0, 0, 0, 0, 0, 0, false, false, 4, 3, 1, dyes::White, 1, {material::stack(Tin, 1), material::stack(Oxygen, 2)});
        material Celestine(913, textures::SET_DULL, 1, 1 | 8, 200, 205, 240, 0, "Celestine", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::LightGray, 1, {material::stack(Strontium, 1), material::stack(Sulfur, 1), material::stack(Oxygen, 4)});
        material Chalcopyrite(855, textures::SET_DULL, 1, 1 | 8, 160, 120, 40, 0, "Chalcopyrite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Yellow, 1, {material::stack(Copper, 1), material::stack(Iron, 1), material::stack(Sulfur, 2)});
        material Charcoal(536, textures::SET_FINE, 1, 1 | 4, 100, 70, 70, 0, "Charcoal", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Black, 1, {material::stack(Carbon, 1)});
        material Chromite(825, textures::SET_METALLIC, 1, 1 | 8, 35, 20, 15, 0, "Chromite", 0, 0, 0, 0, 1700, 1700, true, false, 6, 1, 1, dyes::Pink, 1, {material::stack(Iron, 1), material::stack(Chrome, 2), material::stack(Oxygen, 4)});
        material Cinnabar(826, textures::SET_ROUGH, 1, 1 | 8, 150, 0, 0, 0, "Cinnabar", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Brown, 2, {material::stack(Mercury, 1), material::stack(Sulfur, 1)});
        material Clay(805, textures::SET_DULL, 1, 1, 255, 255, 255, 0, "Clay", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::LightBlue, 1, {material::stack(Sodium, 2), material::stack(Lithium, 1), material::stack(Aluminium, 2), material::stack(Silicon, 2)});
        material Coal(535, textures::SET_ROUGH, 1, 1 | 4 | 8, 70, 70, 70, 0, "Coal", 0, 0, 0, 0, 0, 0, false, false, 2, 2, 1, dyes::Black, 1, {material::stack(Carbon, 1)});
        material Cobaltite(827, textures::SET_METALLIC, 1, 1 | 8, 80, 80, 250, 0, "Cobaltite", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Blue, 1, {material::stack(Cobalt, 1), material::stack(Arsenic, 1), material::stack(Sulfur, 1)});
        material Cooperite(828, textures::SET_METALLIC, 1, 1 | 8, 255, 255, 200, 0, "Cooperite", 0, 0, 0, 0, 0, 0, false, false, 5, 1, 1, dyes::Yellow, 2, {material::stack(Platinum, 3), material::stack(Nickel, 1), material::stack(Sulfur, 1), material::stack(Palladium, 1)});
        material Cupronickel(310, textures::SET_METALLIC, 1, 1 | 2 | 64, 227, 150, 128, 0, "Cupronickel", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Orange, 2, {material::stack(Copper, 1), material::stack(Nickel, 1)});
        material DarkAsh(816, textures::SET_DULL, 1, 1, 50, 50, 50, 0, "Dark Ashes", 0, 0, 0, 0, 0, 0, false, false, 1, 2, 1, dyes::Gray, 1, {material::stack(Carbon, 1)});
        material DeepIron(829, textures::SET_METALLIC, 2, 1 | 2 | 8 | 64, 150, 140, 140, 0, "Deep Iron", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Pink, 2, {material::stack(Iron, 1)});
        material Diamond(500, textures::SET_DIAMOND, 3, 1 | 4 | 8 | 64 | 128, 200, 255, 255, 127, "Diamond", 0, 0, 0, 0, 0, 0, false, true, 5, 128, 1, dyes::White, 1, {material::stack(Carbon, 1)});
        material Electrum(303, textures::SET_SHINY, 2, 1 | 2 | 64 | 128, 255, 255, 100, 0, "Electrum", 0, 0, 0, 0, 0, 0, false, false, 4, 1, 1, dyes::Yellow, 2, {material::stack(Silver, 1), material::stack(Gold, 1)});
        material Emerald(501, textures::SET_EMERALD, 2, 1 | 4 | 8 | 64, 80, 255, 80, 127, "Emerald", 0, 0, 0, 0, 0, 0, false, true, 5, 1, 1, dyes::Green, 1, {material::stack(Beryllium, 3), material::stack(Aluminium, 2), material::stack(Silicon, 6), material::stack(Oxygen, 18)});
        material Galena(830, textures::SET_DULL, 3, 1 | 8, 100, 60, 100, 0, "Galena", 0, 0, 0, 0, 0, 0, false, false, 4, 1, 1, dyes::Purple, 1, {material::stack(Lead, 3), material::stack(Silver, 3), material::stack(Sulfur, 2)});
        material Garnierite(906, textures::SET_METALLIC, 3, 1 | 8, 50, 200, 70, 0, "Garnierite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::LightBlue, 1, {material::stack(Nickel, 1), material::stack(Oxygen, 1)});
        material Glyceryl(714, textures::SET_FLUID, 1, 16, 0, 150, 150, 0, "Glyceryl", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Cyan, 1, {material::stack(Carbon, 3), material::stack(Hydrogen, 5), material::stack(Nitrogen, 3), material::stack(Oxygen, 9)});
        material GreenSapphire(504, textures::SET_GEM_HORIZONTAL, 2, 1 | 4 | 8 | 64, 100, 255, 130, 127, "Green Sapphire", 0, 0, 0, 0, 0, 0, false, true, 5, 1, 1, dyes::Cyan, 1, {material::stack(Aluminium, 2), material::stack(Oxygen, 3)});
        material Grossular(831, textures::SET_ROUGH, 1, 1 | 8, 200, 100, 0, 0, "Grossular", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Orange, 1, {material::stack(Calcium, 3), material::stack(Aluminium, 2), material::stack(Silicon, 3), material::stack(Oxygen, 12)});
        material Ice(702, textures::SET_SHINY, 0, 1 | 16, 200, 200, 255, 0, "Ice", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Blue, 0, {material::stack(Hydrogen, 2), material::stack(Oxygen, 1)});
        material Ilmenite(918, textures::SET_METALLIC, 3, 1 | 8, 70, 55, 50, 0, "Ilmenite", 0, 0, 0, 0, 0, 0, false, false, 1, 2, 1, dyes::Purple, 1, {material::stack(Iron, 1), material::stack(Titanium, 1), material::stack(Oxygen, 3)});
        material Invar(302, textures::SET_METALLIC, 2, 1 | 2 | 64 | 128, 180, 180, 120, 0, "Invar", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Brown, 2, {material::stack(Iron, 2), material::stack(Nickel, 1)});
        material Kanthal(312, textures::SET_METALLIC, 2, 1 | 2 | 64, 194, 210, 223, 0, "Kanthal", 0, 0, 0, 0, 2500, 2500, true, false, 1, 1, 1, dyes::Yellow, 2, {material::stack(Iron, 1), material::stack(Aluminium, 1), material::stack(Chrome, 1)});
        material Lazurite(524, textures::SET_LAPIS, 1, 1 | 4 | 8, 100, 120, 255, 0, "Lazurite", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Cyan, 1, {material::stack(Aluminium, 6), material::stack(Silicon, 6), material::stack(Calcium, 8), material::stack(Sodium, 8)});
        material LiveRoot(832, textures::SET_WOOD, 1, 1, 220, 200, 0, 0, "Liveroot", 5, 16, 0, 0, 0, 0, false, false, 2, 4, 3, dyes::Brown, 2, {material::stack(Wood, 3), material::stack(Magic, 1)});
        material Magnalium(313, textures::SET_DULL, 2, 1 | 2 | 64 | 128, 200, 190, 255, 0, "Magnalium", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::LightBlue, 2, {material::stack(Magnesium, 1), material::stack(Aluminium, 2)});
        material Magnesite(908, textures::SET_METALLIC, 2, 1 | 8, 250, 250, 180, 0, "Magnesite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Pink, 1, {material::stack(Magnesium, 1), material::stack(Carbon, 1), material::stack(Oxygen, 3)});
        material Magnetite(870, textures::SET_METALLIC, 2, 1 | 8, 30, 30, 30, 0, "Magnetite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Gray, 1, {material::stack(Iron, 3), material::stack(Oxygen, 4)});
        material Methane(715, textures::SET_FLUID, 1, 16, 255, 255, 255, 0, "Methane", 1, 45, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Magenta, 1, {material::stack(Carbon, 1), material::stack(Hydrogen, 4)});
        material Molybdenite(942, textures::SET_METALLIC, 2, 1 | 8, 25, 25, 25, 0, "Molybdenite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Blue, 1, {material::stack(Molybdenum, 1), material::stack(Sulfur, 2)}); // MoS2 (also source of Re)
        material Nichrome(311, textures::SET_METALLIC, 2, 1 | 2 | 64, 205, 206, 246, 0, "Nichrome", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Red, 2, {material::stack(Nickel, 4), material::stack(Chrome, 1)});
        material NitroCarbon(716, textures::SET_FLUID, 1, 16, 0, 75, 100, 0, "Nitro-Carbon", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Cyan, 1, {material::stack(Nitrogen, 1), material::stack(Carbon, 1)});
        material NitrogenDioxide(717, textures::SET_FLUID, 1, 16, 100, 175, 255, 0, "Nitrogen Dioxide", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Cyan, 1, {material::stack(Nitrogen, 1), material::stack(Oxygen, 2)});
        material Obsidian(804, textures::SET_DULL, 3, 1, 80, 50, 100, 0, "Obsidian", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Black, 1, {material::stack(Magnesium, 1), material::stack(Iron, 1), material::stack(Silicon, 2), material::stack(Oxygen, 8)});
        material Phosphate(833, textures::SET_DULL, 1, 1 | 8 | 16, 255, 255, 0, 0, "Phosphate", 0, 0, 0, 0, 0, 0, false, false, 2, 1, 1, dyes::Yellow, 1, {material::stack(Phosphor, 1), material::stack(Oxygen, 4)});
        material PigIron(307, textures::SET_METALLIC, 2, 1 | 2 | 8 | 64, 200, 180, 180, 0, "Pig Iron", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Pink, 2, {material::stack(Iron, 1)});
        material Plastic(874, textures::SET_DULL, 1, 1 | 2 | 64 | 128, 200, 200, 200, 0, "Plastic", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::White, 0, {material::stack(Carbon, 1), material::stack(Hydrogen, 2)});
        material Powellite(883, textures::SET_DULL, 2, 1 | 8, 255, 255, 0, 0, "Powellite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Yellow, 2, {material::stack(Calcium, 1), material::stack(Molybdenum, 1), material::stack(Oxygen, 4)});
        material Pumice(926, textures::SET_DULL, 2, 1 | 8, 230, 185, 185, 0, "Pumice", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Gray, 2, {material::stack(Stone, 1)});
        material Pyrite(834, textures::SET_ROUGH, 1, 1 | 8, 150, 120, 40, 0, "Pyrite", 0, 0, 0, 0, 0, 0, false, false, 2, 1, 1, dyes::Orange, 1, {material::stack(Iron, 1), material::stack(Sulfur, 2)});
        material Pyrolusite(943, textures::SET_DULL, 2, 1 | 8, 150, 150, 170, 0, "Pyrolusite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::LightGray, 1, {material::stack(Manganese, 1), material::stack(Oxygen, 2)});
        material Pyrope(835, textures::SET_METALLIC, 2, 1 | 8, 120, 50, 100, 0, "Pyrope", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Purple, 1, {material::stack(Aluminium, 2), material::stack(Magnesium, 3), material::stack(Silicon, 3), material::stack(Oxygen, 12)});
        material RockSalt(944, textures::SET_FINE, 1, 1 | 8, 240, 200, 200, 0, "Rock Salt", 0, 0, 0, 0, 0, 0, false, false, 2, 1, 1, dyes::White, 1, {material::stack(Potassium, 1), material::stack(Chlorine, 1)});
        material Rubber(880, textures::SET_SHINY, 0, 1 | 2 | 64 | 128, 0, 0, 0, 0, "Rubber", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Black, 0, {material::stack(Carbon, 5), material::stack(Hydrogen, 8)});
        material Ruby(502, textures::SET_RUBY, 2, 1 | 4 | 8 | 64, 255, 100, 100, 127, "Ruby", 0, 0, 0, 0, 0, 0, false, true, 5, 1, 1, dyes::Red, 1, {material::stack(Chrome, 1), material::stack(Aluminium, 2), material::stack(Oxygen, 3)});
        material Salt(817, textures::SET_FINE, 1, 1 | 8, 250, 250, 250, 0, "Salt", 0, 0, 0, 0, 0, 0, false, false, 2, 1, 1, dyes::White, 1, {material::stack(Sodium, 1), material::stack(Chlorine, 1)});
        material Saltpeter(836, textures::SET_FINE, 1, 1 | 8, 230, 230, 230, 0, "Saltpeter", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::White, 1, {material::stack(Potassium, 1), material::stack(Nitrogen, 1), material::stack(Oxygen, 3)});
        material Sapphire(503, textures::SET_GEM_VERTICAL, 2, 1 | 4 | 8 | 64, 100, 100, 200, 127, "Sapphire", 0, 0, 0, 0, 0, 0, false, true, 5, 1, 1, dyes::Blue, 1, {material::stack(Aluminium, 2), material::stack(Oxygen, 3)});
        material Scheelite(910, textures::SET_DULL, 3, 1 | 8, 200, 140, 20, 0, "Scheelite", 0, 0, 0, 0, 2500, 2500, false, false, 4, 1, 1, dyes::Black, 1, {material::stack(Tungsten, 1), material::stack(Calcium, 2), material::stack(Oxygen, 4)});
        material SiliconDioxide(837, textures::SET_QUARTZ, 1, 1 | 16, 255, 255, 255, 0, "Silicon Dioxide", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::LightGray, 1, {material::stack(Silicon, 1), material::stack(Oxygen, 2)});
        material Sodalite(525, textures::SET_LAPIS, 1, 1 | 4 | 8, 20, 20, 255, 0, "Sodalite", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Blue, 1, {material::stack(Aluminium, 3), material::stack(Silicon, 3), material::stack(Sodium, 4), material::stack(Chlorine, 1)});
        material SodiumPersulfate(718, textures::SET_FLUID, 2, 16, 255, 255, 255, 0, "Sodium Persulfate", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Orange, 1, {material::stack(Sodium, 1), material::stack(Sulfur, 1), material::stack(Oxygen, 4)});
        material SodiumSulfide(719, textures::SET_FLUID, 2, 16, 255, 255, 255, 0, "Sodium Sulfide", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Orange, 1, {material::stack(Sodium, 1), material::stack(Sulfur, 1)});
        material SolderingAlloy(314, textures::SET_DULL, 1, 1 | 2, 220, 220, 230, 0, "Soldering Alloy", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::White, 2, {material::stack(Tin, 9), material::stack(Antimony, 1)});
        material Spessartine(838, textures::SET_DULL, 2, 1 | 8, 255, 100, 100, 0, "Spessartine", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Red, 1, {material::stack(Aluminium, 2), material::stack(Manganese, 3), material::stack(Silicon, 3), material::stack(Oxygen, 12)});
        material Sphalerite(839, textures::SET_DULL, 1, 1 | 8, 255, 255, 255, 0, "Sphalerite", 0, 0, 0, 0, 0, 0, false, false, 2, 1, 1, dyes::Yellow, 1, {material::stack(Zinc, 1), material::stack(Sulfur, 1)});
        material StainlessSteel(306, textures::SET_SHINY, 3, 1 | 2 | 64 | 128, 200, 200, 220, 0, "Stainless Steel", 0, 0, 0, 0, 1700, 1700, true, false, 1, 1, 1, dyes::White, 1, {material::stack(Iron, 6), material::stack(Chrome, 1), material::stack(Manganese, 1), material::stack(Nickel, 1)});
        material Steel(305, textures::SET_METALLIC, 3, 1 | 2 | 64 | 128, 128, 128, 128, 0, "Steel", 0, 0, 0, 0, 1000, 1000, true, false, 4, 51, 50, dyes::Gray, 1, {material::stack(Iron, 50), material::stack(Carbon, 1)});
        material Stibnite(945, textures::SET_METALLIC, 2, 1 | 8, 70, 70, 70, 0, "Stibnite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::White, 2, {material::stack(Antimony, 2), material::stack(Sulfur, 3)});
        material SulfuricAcid(720, textures::SET_FLUID, 2, 16, 255, 128, 0, 0, "Sulfuric Acid", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Orange, 1, {material::stack(Hydrogen, 2), material::stack(Sulfur, 1), material::stack(Oxygen, 4)});
        material Tanzanite(508, textures::SET_GEM_VERTICAL, 2, 1 | 4 | 8 | 64, 64, 0, 200, 127, "Tanzanite", 0, 0, 0, 0, 0, 0, false, true, 5, 1, 1, dyes::Purple, 1, {material::stack(Calcium, 2), material::stack(Aluminium, 3), material::stack(Silicon, 3), material::stack(Hydrogen, 1), material::stack(Oxygen, 13)});
        material Tetrahedrite(840, textures::SET_DULL, 2, 1 | 8, 200, 32, 0, 0, "Tetrahedrite", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Red, 2, {material::stack(Copper, 3), material::stack(Antimony, 1), material::stack(Sulfur, 3), material::stack(Iron, 1)}); //Cu3SbS3 + x(Fe,Zn)6Sb2S9
        material Topaz(507, textures::SET_GEM_HORIZONTAL, 3, 1 | 4 | 8 | 64, 255, 128, 0, 127, "Topaz", 0, 0, 0, 0, 0, 0, false, true, 5, 1, 1, dyes::Orange, 1, {material::stack(Aluminium, 2), material::stack(Silicon, 1), material::stack(Fluorine, 2), material::stack(Hydrogen, 2), material::stack(Oxygen, 6)});
        material Tungstate(841, textures::SET_DULL, 3, 1 | 8, 55, 50, 35, 0, "Tungstate", 0, 0, 0, 0, 2500, 2500, true, false, 4, 1, 1, dyes::Black, 1, {material::stack(Tungsten, 1), material::stack(Lithium, 2), material::stack(Oxygen, 4)});
        material Ultimet(344, textures::SET_SHINY, 3, 1 | 2 | 64 | 128, 180, 180, 230, 0, "Ultimet", 0, 0, 0, 0, 2700, 2700, true, false, 1, 1, 1, dyes::LightBlue, 1, {material::stack(Cobalt, 5), material::stack(Chrome, 2), material::stack(Nickel, 1), material::stack(Molybdenum, 1)}); // 54% Cobalt, 26% Chromium, 9% Nickel, 5% Molybdenum, 3% Iron, 2% Tungsten, 0.8% Manganese, 0.3% Silicon, 0.08% Nitrogen and 0.06% Carbon
        material Uraninite(922, textures::SET_METALLIC, 3, 1 | 8, 35, 35, 35, 0, "Uraninite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Lime, 2, {material::stack(Uranium, 1), material::stack(Oxygen, 2)});
        material Uvarovite(842, textures::SET_DIAMOND, 2, 1 | 8, 180, 255, 180, 0, "Uvarovite", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Green, 1, {material::stack(Calcium, 3), material::stack(Chrome, 2), material::stack(Silicon, 3), material::stack(Oxygen, 12)});
        material Water(701, textures::SET_FLUID, 0, 16, 0, 0, 255, 0, "Water", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Blue, 0, {material::stack(Hydrogen, 2), material::stack(Oxygen, 1)});
        material Wulfenite(882, textures::SET_DULL, 3, 1 | 8, 255, 128, 0, 0, "Wulfenite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Orange, 2, {material::stack(Lead, 1), material::stack(Molybdenum, 1), material::stack(Oxygen, 4)});
        material WroughtIron(304, textures::SET_METALLIC, 2, 1 | 2 | 64, 200, 180, 180, 0, "Wrought Iron", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::LightGray, 2, {material::stack(Iron, 1)});
        material YellowLimonite(931, textures::SET_METALLIC, 2, 1 | 8, 200, 200, 0, 0, "Yellow Limonite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Yellow, 2, {material::stack(Iron, 1), material::stack(Hydrogen, 1), material::stack(Oxygen, 2)}); // FeO(OH) + a bit Ni and Co

        /**
        * Second Degree Compounds
        */
        material Perlite(925, textures::SET_DULL, 1, 1 | 8, 30, 20, 30, 0, "Perlite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Black, 2, {material::stack(Obsidian, 2), material::stack(Water, 1)});
        material Borax(941, textures::SET_FINE, 1, 1 | 8, 250, 250, 250, 0, "Borax", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::White, 1, {material::stack(Sodium, 2), material::stack(Boron, 4), material::stack(Water, 10), material::stack(Oxygen, 7)});
        material Lignite(538, textures::SET_LIGNITE, 0, 1 | 4 | 8, 100, 70, 70, 0, "Lignite Coal", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Black, 1, {material::stack(Carbon, 2), material::stack(Water, 4), material::stack(DarkAsh, 1)});
        material Olivine(505, textures::SET_RUBY, 2, 1 | 4 | 8 | 64, 150, 255, 150, 127, "Olivine", 0, 0, 0, 0, 0, 0, false, true, 5, 1, 1, dyes::Lime, 1, {material::stack(Magnesium, 2), material::stack(Iron, 1), material::stack(SiliconDioxide, 2)});
        material Opal(510, textures::SET_OPAL, 2, 1 | 4 | 8 | 64, 0, 0, 255, 0, "Opal", 0, 0, 0, 0, 0, 0, false, true, 3, 1, 1, dyes::Blue, 1, {material::stack(SiliconDioxide, 1)});
        material Amethyst(509, textures::SET_FLINT, 3, 1 | 4 | 8 | 64, 210, 50, 210, 127, "Amethyst", 0, 0, 0, 0, 0, 0, false, true, 3, 1, 1, dyes::Pink, 1, {material::stack(SiliconDioxide, 4), material::stack(Iron, 1)});
        material Redstone(810, textures::SET_ROUGH, 2, 1 | 8, 200, 0, 0, 0, "Redstone", 0, 0, 5000, 0, 0, 0, false, false, 3, 1, 1, dyes::Red, 2, {material::stack(Silicon, 1), material::stack(Pyrite, 5), material::stack(Ruby, 1), material::stack(Mercury, 3)});
        material Lapis(526, textures::SET_LAPIS, 1, 1 | 4 | 8, 70, 70, 220, 0, "Lapis", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Blue, 2, {material::stack(Lazurite, 12), material::stack(Sodalite, 2), material::stack(Pyrite, 1), material::stack(Calcite, 1)});
        material Blaze(801, textures::SET_SHINY, 1, 1 | 64, 255, 255, 255, 0, "Blaze", 0, 0, 0, 0, 0, 0, false, false, 2, 3, 2, dyes::Yellow, 2, {material::stack(DarkAsh, 1), material::stack(Sulfur, 1), material::stack(Magic, 1)});
        material EnderPearl(532, textures::SET_SHINY, 0, 1, 108, 220, 200, 0, "Enderpearl", 0, 0, 25000, 0, 0, 0, false, false, 1, 16, 10, dyes::Green, 1, {material::stack(Beryllium, 1), material::stack(Potassium, 4), material::stack(Nitrogen, 5), material::stack(Magic, 6)});
        material EnderEye(533, textures::SET_SHINY, 0, 1, 160, 250, 230, 0, "Endereye", 5, 10, 50000, 0, 0, 0, false, false, 1, 2, 1, dyes::Green, 2, {material::stack(EnderPearl, 1), material::stack(Blaze, 1)});
        material Flint(802, textures::SET_FLINT, 1, 1 | 64, 0, 32, 64, 0, "Flint", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Gray, 2, {material::stack(SiliconDioxide, 1)});
        material Diatomite(948, textures::SET_DULL, 1, 1 | 8, 225, 225, 225, 0, "Diatomite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Gray, 2, {material::stack(Flint, 8), material::stack(BandedIron, 1), material::stack(Sapphire, 1)});
        material VolcanicAsh(940, textures::SET_FLINT, 0, 1, 60, 50, 50, 0, "Volcanic Ashes", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Black, 2, {material::stack(Flint, 6), material::stack(Iron, 1), material::stack(Magnesium, 1)});
        material Niter(531, textures::SET_FLINT, 1, 1 | 4 | 8, 255, 200, 200, 0, "Niter", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Pink, 2, {material::stack(Saltpeter, 1)});
        material Pyrotheum(843, textures::SET_SHINY, 1, 1, 255, 128, 0, 0, "Pyrotheum", 2, 62, 0, 0, 0, 0, false, false, 2, 3, 1, dyes::Yellow, 2, {material::stack(Coal, 1), material::stack(Redstone, 1), material::stack(Blaze, 1)});
        material HydratedCoal(818, textures::SET_ROUGH, 1, 1, 70, 70, 100, 0, "Hydrated Coal", 0, 0, 0, 0, 0, 0, false, false, 1, 9, 8, dyes::Black, 2, {material::stack(Coal, 8), material::stack(Water, 1)});
        material Apatite(530, textures::SET_DIAMOND, 1, 1 | 4 | 8, 200, 200, 255, 0, "Apatite", 0, 0, 0, 0, 0, 0, false, false, 2, 1, 1, dyes::Cyan, 1, {material::stack(Calcium, 5), material::stack(Phosphate, 3), material::stack(Chlorine, 1)});
        material Alumite(-1, textures::SET_METALLIC, 0, 1 | 2 | 64, 255, 255, 255, 0, "Alumite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Pink, 2, {material::stack(Aluminium, 5), material::stack(Iron, 2), material::stack(Obsidian, 2)});
        material Manyullyn(-1, textures::SET_METALLIC, 0, 1 | 2 | 64, 255, 255, 255, 0, "Manyullyn", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Purple, 2, {material::stack(Cobalt, 1), material::stack(Aredrite, 1)});
        material IronWood(338, textures::SET_WOOD, 2, 1 | 2 | 64 | 128, 220, 175, 0, 0, "Ironwood", 5, 8, 0, 0, 0, 0, false, false, 2, 19, 9, dyes::Brown, 2, {material::stack(Iron, 9), material::stack(LiveRoot, 9), material::stack(Gold, 1)});
        material ShadowIron(336, textures::SET_METALLIC, 2, 1 | 2 | 8 | 64, 120, 120, 120, 0, "Shadowiron", 0, 0, 0, 0, 0, 0, false, false, 3, 4, 3, dyes::Black, 2, {material::stack(Iron, 3), material::stack(Magic, 1)});
        material ShadowSteel(337, textures::SET_METALLIC, 3, 1 | 2 | 64, 90, 90, 90, 0, "Shadowsteel", 0, 0, 0, 0, 1700, 1700, true, false, 4, 4, 3, dyes::Black, 2, {material::stack(Steel, 3), material::stack(Magic, 1)});
        material SteelLeaf(339, textures::SET_LEAF, 3, 1 | 2 | 64, 0, 127, 0, 0, "Steelleaf", 5, 24, 0, 0, 0, 0, false, false, 4, 1, 1, dyes::Green, 2, {material::stack(Steel, 1), material::stack(Magic, 1)});
        material BlackSteel(334, textures::SET_METALLIC, 3, 1 | 2 | 64, 100, 100, 100, 0, "Black Steel", 0, 0, 0, 0, 1200, 1200, true, false, 4, 1, 1, dyes::Black, 2, {material::stack(Steel, 1)});
        material DamascusSteel(335, textures::SET_METALLIC, 3, 1 | 2 | 64, 110, 110, 110, 0, "Damascus Steel", 0, 0, 0, 0, 1500, 1500, true, false, 4, 1, 1, dyes::Gray, 2, {material::stack(Steel, 1)});
        material TungstenSteel(316, textures::SET_METALLIC, 4, 1 | 2 | 64 | 128, 100, 100, 160, 0, "Tungstensteel", 0, 0, 0, 0, 3000, 3000, true, false, 4, 1, 1, dyes::Blue, 2, {material::stack(Steel, 1), material::stack(Tungsten, 1)});
        material NitroCoalFuel(711, textures::SET_FLUID, 2, 16, 50, 70, 50, 0, "Nitro-Coalfuel", 0, 48, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Black, 0, {material::stack(Glyceryl, 1), material::stack(CoalFuel, 4)});
        material NitroFuel(709, textures::SET_FLUID, 2, 16, 200, 255, 0, 0, "Nitro-Diesel", 0, 384, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Lime, 0, {material::stack(Glyceryl, 1), material::stack(Fuel, 4)});
        material AstralSilver(333, textures::SET_SHINY, 2, 1 | 2 | 8 | 64, 230, 230, 255, 0, "Astral Silver", 0, 0, 0, 0, 0, 0, false, false, 4, 3, 2, dyes::White, 2, {material::stack(Silver, 2), material::stack(Magic, 1)});
        material Midasium(332, textures::SET_SHINY, 2, 1 | 2 | 8 | 64, 255, 200, 40, 0, "Midasium", 0, 0, 0, 0, 0, 0, false, false, 4, 3, 2, dyes::Orange, 2, {material::stack(Gold, 2), material::stack(Magic, 1)});
        material Mithril(331, textures::SET_SHINY, 3, 1 | 2 | 8 | 64, 255, 255, 210, 0, "Mithril", 0, 0, 0, 0, 0, 0, false, false, 4, 3, 2, dyes::LightBlue, 2, {material::stack(Platinum, 2), material::stack(Magic, 1)});
        material BlueAlloy(309, textures::SET_DULL, 0, 1 | 2, 100, 180, 255, 0, "Blue Alloy", 0, 0, 0, 0, 0, 0, false, false, 3, 5, 1, dyes::LightBlue, 2, {material::stack(Silver, 1), material::stack(Nikolite, 4)});
        material RedAlloy(308, textures::SET_DULL, 0, 1 | 2, 200, 0, 0, 0, "Red Alloy", 0, 0, 0, 0, 0, 0, false, false, 3, 5, 1, dyes::Red, 2, {material::stack(Metal, 1), material::stack(Redstone, 4)});
        material CobaltBrass(343, textures::SET_METALLIC, 2, 1 | 2 | 64 | 128, 180, 180, 160, 0, "Cobalt Brass", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Orange, 2, {material::stack(Brass, 7), material::stack(Aluminium, 1), material::stack(Cobalt, 1)});
        material Phosphorus(534, textures::SET_FLINT, 2, 1 | 4 | 8 | 16, 255, 255, 0, 0, "Phosphorus", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Yellow, 2, {material::stack(Calcium, 3), material::stack(Phosphate, 2)});
        material Basalt(844, textures::SET_ROUGH, 1, 1, 30, 20, 20, 0, "Basalt", 0, 0, 0, 0, 0, 0, false, false, 2, 1, 1, dyes::Black, 2, {material::stack(Olivine, 1), material::stack(Calcite, 3), material::stack(Flint, 8), material::stack(DarkAsh, 4)});
        material GarnetRed(527, textures::SET_RUBY, 2, 1 | 4 | 8 | 64, 200, 80, 80, 127, "Red Garnet", 0, 0, 0, 0, 0, 0, false, true, 4, 1, 1, dyes::Red, 2, {material::stack(Pyrope, 3), material::stack(Almandine, 5), material::stack(Spessartine, 8)});
        material GarnetYellow(528, textures::SET_RUBY, 2, 1 | 4 | 8 | 64, 200, 200, 80, 127, "Yellow Garnet", 0, 0, 0, 0, 0, 0, false, true, 4, 1, 1, dyes::Yellow, 2, {material::stack(Andradite, 5), material::stack(Grossular, 8), material::stack(Uvarovite, 3)});
        material Marble(845, textures::SET_FINE, 1, 1, 200, 200, 200, 0, "Marble", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::White, 2, {material::stack(Magnesium, 1), material::stack(Calcite, 7)});
        material Sugar(803, textures::SET_FINE, 1, 1, 250, 250, 250, 0, "Sugar", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::White, 1, {material::stack(Carbon, 2), material::stack(Water, 5), material::stack(Oxygen, 25)});
        material Thaumium(330, textures::SET_SHINY, 3, 1 | 2 | 64 | 128, 100, 0, 200, 0, "Thaumium", 0, 0, 0, 0, 0, 0, false, false, 5, 2, 1, dyes::Purple, 0, {material::stack(Metal, 1), material::stack(Magic, 1)});
        material Vinteum(529, textures::SET_EMERALD, 3, 1 | 4 | 8 | 64, 100, 200, 255, 0, "Vinteum", 5, 32, 0, 0, 0, 0, false, false, 4, 1, 1, dyes::LightBlue, 2, {material::stack(Magic, 1)});
        material Vis(-1, textures::SET_SHINY, 3, 0, 128, 0, 255, 0, "Vis", 5, 32, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Purple, 2, {material::stack(Magic, 1)});
        material Redrock(846, textures::SET_ROUGH, 1, 1, 255, 80, 50, 0, "Redrock", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Red, 2, {material::stack(Calcite, 2), material::stack(Flint, 1), material::stack(Clay, 1)});
        material PotassiumFeldspar(847, textures::SET_FINE, 1, 1, 120, 40, 40, 0, "Potassium Feldspar", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Pink, 1, {material::stack(Potassium, 1), material::stack(Aluminium, 1), material::stack(Silicon, 3), material::stack(Oxygen, 8)});
        material Biotite(848, textures::SET_METALLIC, 1, 1, 20, 30, 20, 0, "Biotite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Gray, 1, {material::stack(Potassium, 1), material::stack(Magnesium, 3), material::stack(Aluminium, 3), material::stack(Fluorine, 2), material::stack(Silicon, 3), material::stack(Oxygen, 10)});
        material GraniteBlack(849, textures::SET_ROUGH, 3, 1 | 64 | 128, 10, 10, 10, 0, "Black Granite", 0, 0, 0, 0, 0, 0, false, false, 0, 1, 1, dyes::Black, 2, {material::stack(SiliconDioxide, 4), material::stack(Biotite, 1)});
        material GraniteRed(850, textures::SET_ROUGH, 3, 1 | 64 | 128, 255, 0, 128, 0, "Red Granite", 0, 0, 0, 0, 0, 0, false, false, 0, 1, 1, dyes::Magenta, 1, {material::stack(Aluminium, 2), material::stack(PotassiumFeldspar, 1), material::stack(Oxygen, 3)});
        material Chrysotile(912, textures::SET_DULL, 2, 1 | 8, 110, 140, 110, 0, "Chrysotile", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::White, 2, {material::stack(Asbestos, 1)});
        material VanadiumMagnetite(923, textures::SET_METALLIC, 2, 1 | 8, 35, 35, 60, 0, "Vanadium Magnetite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Black, 2, {material::stack(Magnetite, 1), material::stack(Vanadium, 1)}); // Mixture of Fe3O4 and V2O5
        material BasalticMineralSand(935, textures::SET_SAND, 1, 1 | 8, 40, 50, 40, 0, "Basaltic Mineral Sand", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Black, 2, {material::stack(Magnetite, 1), material::stack(Basalt, 1)});
        material GraniticMineralSand(936, textures::SET_SAND, 1, 1 | 8, 40, 60, 60, 0, "Granitic Mineral Sand", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Black, 2, {material::stack(Magnetite, 1), material::stack(GraniteBlack, 1)});
        material GarnetSand(938, textures::SET_SAND, 1, 1 | 8, 200, 100, 0, 0, "Garnet Sand", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::Orange, 2, {material::stack(GarnetRed, 1), material::stack(GarnetYellow, 1)});
        material QuartzSand(939, textures::SET_SAND, 1, 1 | 8, 200, 200, 200, 0, "Quartz Sand", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::White, 2, {material::stack(CertusQuartz, 1), material::stack(Quartzite, 1)});
        material Bastnasite(905, textures::SET_FINE, 2, 1 | 8, 200, 110, 45, 0, "Bastnasite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL, 1, {material::stack(Cerium, 1), material::stack(Carbon, 1), material::stack(Fluorine, 1), material::stack(Oxygen, 3)}); // (Ce, La, Y)CO3F
        material Pentlandite(909, textures::SET_DULL, 2, 1 | 8, 165, 150, 5, 0, "Pentlandite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL, 1, {material::stack(Nickel, 9), material::stack(Sulfur, 8)}); // (Fe,Ni)9S8
        material Spodumene(920, textures::SET_DULL, 2, 1 | 8, 190, 170, 170, 0, "Spodumene", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL, 1, {material::stack(Lithium, 1), material::stack(Aluminium, 1), material::stack(Silicon, 2), material::stack(Oxygen, 6)}); // LiAl(SiO3)2
        material Pollucite(919, textures::SET_DULL, 2, 1 | 8, 240, 210, 210, 0, "Pollucite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL, 1, {material::stack(Caesium, 2), material::stack(Aluminium, 2), material::stack(Silicon, 4), material::stack(Water, 2), material::stack(Oxygen, 12)}); // (Cs,Na)2Al2Si4O12 2H2O (also a source of Rb)
        material Tantalite(921, textures::SET_METALLIC, 3, 1 | 8, 145, 80, 40, 0, "Tantalite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL, 1, {material::stack(Manganese, 1), material::stack(Tantalum, 2), material::stack(Oxygen, 6)}); // (Fe, Mn)Ta2O6 (also source of Nb)
        material Lepidolite(907, textures::SET_FINE, 2, 1 | 8, 240, 50, 140, 0, "Lepidolite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL, 1, {material::stack(Potassium, 1), material::stack(Lithium, 3), material::stack(Aluminium, 4), material::stack(Fluorine, 2), material::stack(Oxygen, 10)}); // K(Li,Al,Rb)3(Al,Si)4O10(F,OH)2
        material Glauconite(933, textures::SET_DULL, 2, 1 | 8, 130, 180, 60, 0, "Glauconite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL, 1, {material::stack(Potassium, 1), material::stack(Magnesium, 2), material::stack(Aluminium, 4), material::stack(Hydrogen, 2), material::stack(Oxygen, 12)}); // (K,Na)(Fe3+,Al,Mg)2(Si,Al)4O10(OH)2
        material Vermiculite(932, textures::SET_METALLIC, 2, 1 | 8, 200, 180, 15, 0, "Vermiculite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL, 1, {material::stack(Iron, 3), material::stack(Aluminium, 4), material::stack(Silicon, 4), material::stack(Hydrogen, 2), material::stack(Water, 4), material::stack(Oxygen, 12)}); // (Mg+2, Fe+2, Fe+3)3 [(AlSi)4O10] (OH)2 4H2O)
        material Bentonite(927, textures::SET_ROUGH, 2, 1 | 8, 245, 215, 210, 0, "Bentonite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL, 1, {material::stack(Sodium, 1), material::stack(Magnesium, 6), material::stack(Silicon, 12), material::stack(Hydrogen, 6), material::stack(Water, 5), material::stack(Oxygen, 36)}); // (Na,Ca)0.33(Al,Mg)2(Si4O10)(OH)2 nH2O
        material FullersEarth(928, textures::SET_FINE, 2, 1 | 8, 160, 160, 120, 0, "Fullers Earth", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL, 1, {material::stack(Magnesium, 1), material::stack(Silicon, 4), material::stack(Hydrogen, 1), material::stack(Water, 4), material::stack(Oxygen, 11)}); // (Mg,Al)2Si4O10(OH) 4(H2O)
        material Pitchblende(873, textures::SET_DULL, 3, 1 | 8, 200, 210, 0, 0, "Pitchblende", 0, 0, 0, 0, 0, 0, false, false, 5, 1, 1, dyes::Yellow, 2, {material::stack(Uraninite, 3), material::stack(Thorium, 1), material::stack(Lead, 1)});
        material Malachite(871, textures::SET_DULL, 2, 1 | 8, 5, 95, 5, 0, "Malachite", 0, 0, 0, 0, 0, 0, false, false, 3, 1, 1, dyes::Green, 1, {material::stack(Copper, 2), material::stack(Carbon, 1), material::stack(Hydrogen, 2), material::stack(Oxygen, 5)}); // Cu2CO3(OH)2
        material Mirabilite(900, textures::SET_DULL, 2, 1 | 8, 240, 250, 210, 0, "Mirabilite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL, 1, {material::stack(Sodium, 2), material::stack(Sulfur, 1), material::stack(Water, 10), material::stack(Oxygen, 4)}); // Na2SO4 10H2O
        material Mica(901, textures::SET_FINE, 1, 1 | 8, 195, 195, 205, 0, "Mica", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL, 1, {material::stack(Potassium, 1), material::stack(Aluminium, 3), material::stack(Silicon, 3), material::stack(Fluorine, 2), material::stack(Oxygen, 10)}); // KAl2(AlSi3O10)(F,OH)2
        material Trona(903, textures::SET_METALLIC, 1, 1 | 8, 135, 135, 95, 0, "Trona", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL, 1, {material::stack(Sodium, 3), material::stack(Carbon, 2), material::stack(Hydrogen, 1), material::stack(Water, 2), material::stack(Oxygen, 6)}); // Na3(CO3)(HCO3) 2H2O
        material Barite(904, textures::SET_DULL, 2, 1 | 8, 230, 235, 255, 0, "Barite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL, 1, {material::stack(Barium, 1), material::stack(Sulfur, 1), material::stack(Oxygen, 4)});
        material Gypsum(934, textures::SET_DULL, 1, 1 | 8, 230, 230, 250, 0, "Gypsum", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL, 1, {material::stack(Calcium, 1), material::stack(Sulfur, 1), material::stack(Water, 2), material::stack(Oxygen, 4)}); // CaSO4 2H2O
        material Alunite(911, textures::SET_METALLIC, 2, 1 | 8, 225, 180, 65, 0, "Alunite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL, 1, {material::stack(Potassium, 1), material::stack(Aluminium, 3), material::stack(Silicon, 2), material::stack(Hydrogen, 6), material::stack(Oxygen, 14)}); // KAl3(SO4)2(OH)6
        material Dolomite(914, textures::SET_FLINT, 1, 1 | 8, 225, 205, 205, 0, "Dolomite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL, 1, {material::stack(Calcium, 1), material::stack(Magnesium, 1), material::stack(Carbon, 2), material::stack(Oxygen, 6)}); // CaMg(CO3)2
        material Wollastonite(915, textures::SET_DULL, 2, 1 | 8, 240, 240, 240, 0, "Wollastonite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL, 1, {material::stack(Calcium, 1), material::stack(Silicon, 1), material::stack(Oxygen, 3)}); // CaSiO3
        material Zeolite(916, textures::SET_DULL, 2, 1 | 8, 240, 230, 230, 0, "Zeolite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL, 1, {material::stack(Sodium, 1), material::stack(Calcium, 4), material::stack(Silicon, 27), material::stack(Aluminium, 9), material::stack(Water, 28), material::stack(Oxygen, 72)}); // NaCa4(Si27Al9)O72 28(H2O)
        material Kyanite(924, textures::SET_FLINT, 2, 1 | 8, 110, 110, 250, 0, "Kyanite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL, 1, {material::stack(Aluminium, 2), material::stack(Silicon, 1), material::stack(Oxygen, 5)}); // Al2SiO5
        material Kaolinite(929, textures::SET_DULL, 2, 1 | 8, 245, 235, 235, 0, "Kaolinite", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL, 1, {material::stack(Aluminium, 2), material::stack(Silicon, 2), material::stack(Hydrogen, 4), material::stack(Oxygen, 9)}); // Al2Si2O5(OH)4
        material Talc(902, textures::SET_DULL, 2, 1 | 8, 90, 180, 90, 0, "Talc", 0, 0, 0, 0, 0, 0, false, false, 1, 1, 1, dyes::_NULL, 1, {material::stack(Magnesium, 3), material::stack(Silicon, 4), material::stack(Hydrogen, 2), material::stack(Oxygen, 12)}); // H2Mg3(SiO3)4 

        /**
        * Materials which are renamed automatically
        */
        material Palygorskite(FullersEarth, false);
        material Adamantine(Adamantium, true);
        material FzDarkIron(DarkIron, false);
        material FZDarkIron(DarkIron, false);
        material Ashes(Ash, false);
        material DarkAshes(DarkAsh, false);
        material Abyssal(Basalt, false);
        material Adamant(Adamantium, true);
        material AluminumBrass(AluminiumBrass, false);
        material Aluminum(Aluminium, false);
        material NaturalAluminum(Aluminium, false);
        material NaturalAluminium(Aluminium, false);
        material Americum(Americium, false);
        material Beryl(Emerald, false);
        material BlackGranite(GraniteBlack, false);
        material CalciumCarbonate(Calcite, false);
        material CreosoteOil(Creosote, false);
        material Chromium(Chrome, false);
        material Diesel(Fuel, false);
        material Enderpearl(EnderPearl, false);
        material Endereye(EnderEye, false);
        material EyeOfEnder(EnderEye, false);
        material Eyeofender(EnderEye, false);
        material Flour(Wheat, false);
        material Garnet(GarnetRed, true);
        material Granite(GraniteBlack, false);
        material Kalium(Potassium, false);
        material Lapislazuli(Lapis, false);
        material LapisLazuli(Lapis, false);
        material Monazit(Monazite, false);
        material Natrium(Sodium, false);
        material NitroDiesel(NitroFuel, false);
        material Obby(Obsidian, false);
        material Peridot(Olivine, true);
        material Phosphorite(Phosphorus, true);
        material Quarried(Marble, false);
        material Quicksilver(Mercury, true);
        material QuickSilver(Mercury, false);
        material RedRock(Redrock, false);
        material RefinedIron(Iron, false);
        material RedGranite(GraniteRed, false);
        material Sheldonite(Cooperite, false);
        material Soulsand(SoulSand, false);
        material SilverLead(Galena, false);
        material Titan(Titanium, false);
        material Uran(Uranium, false);
        material Wolframite(Tungstate, false);
        material Wolframium(Tungsten, false);
        material Wolfram(Tungsten, false);
        material WrougtIron(WroughtIron, false);
    }
}