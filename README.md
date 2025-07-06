![SpriteFoundry Logo](SpriteFoundry_logo.png)


**SpriteFoundry** is a modular sprite rigging, animation, and asset packaging tool built for use with [Dexium 2D](https://github.com/Dextron12/Dexium2D). It streamlines the process of preparing complex sprite setups, managing anchor points, modular animations, and bundling game assets into Dexium’s custom `.dexpak` format.

Whether you're developing a modular character system, a particle-based rig, or want to animate individual sprite parts like arms and hair — **SpriteFoundry** gives you the tools to rig, preview, and export your assets directly into Dexium-ready packs.

---

## 🧰 Features

- 🖼 **Spritesheet Canvas Editor**
  - Drag & drop spritesheets
  - Assign subtextures
  - Set up animation frames and sequences
  - Define anchor points and hierarchical layering

- 🧩 **Modular Rigging System**
  - Attach parts (e.g. head, arm, gear) to parent bones or subtextures
  - Supports modular, swappable sprite pieces
  - Create skeletal-like rigs without bones

- 🧠 **Animation Preview**
  - Timeline-based animation system
  - Real-time preview of animation sequences
  - Frame-duration and interpolation controls (planned)

- 🔐 **Asset Packaging**
  - Export all spritesheets, animations, and metadata into a `.dexpak` file
  - Supports optional encryption and password protection
  - Compression support (planned)

- 🔁 **Multi-atlas Support**
  - A single `.dexpak` file can include multiple spritesheets
  - Each subtexture/animation maintains cross-reference support

---

## 📦 DexPak Export Format

When exported, a `.dexpak` file includes:

- A **magic header** and versioning tag
- Optional **encryption key** for tamper protection
- Binary blobs for:
  - Raw textures
  - Subtexture definitions
  - Animation sequences
  - Anchor points
  - Physics data (optional)
  - Metadata index

All assets are indexed and aligned for fast seek & VFS-style loading via Dexium's `AssetManager`.

> Dexium can automatically load these assets using only the `.dexpak` and a reference ID:
```cpp
auto& player = AssetManager::get().use<AnimatedSprite>("player");
```

---

## 🚀 Quickstart (Planned CLI)

```bash
spritefoundry pack ./assets/character.yaml -o game.dexpak --encrypt
```

### Example Input YAML (planned format)
```yaml
spritesheet: Assets/Characters/Player_01.png
subtextures:
  idle: { x: 0, y: 0, w: 32, h: 32 }
  walk1: { x: 32, y: 0, w: 32, h: 32 }
animations:
  idle:
    - frame: idle
      duration: 500
  walk:
    - frame: walk1
      duration: 150
```

---

## 📅 Roadmap

| Feature                             | Status       |
|------------------------------------|--------------|
| GUI Canvas Editor                  | ✅ In progress |
| CLI Packager                       | ✅ Basic       |
| Subtexture & Anchor Editing        | ✅ Working     |
| Modular Sprite Rigging             | ✅ Partial     |
| Export to `.dexpak`                | ✅ Supported   |
| Password-protected `.dexpak`       | ✅ Supported   |
| Physics metadata (AABB, offsets)   | ⏳ Planned     |
| JSON/YAML import/export            | ⏳ Planned     |
| Timeline Animation Editor          | ⏳ Planned     |
| IK-style rigging or bones          | 🧪 Experimental |
| Unity/Godot-style blend trees      | ❌ Not planned |

---

## 📎 Integration with Dexium 2D

SpriteFoundry is designed as a first-class companion to **Dexium 2D**:

- All exported `.dexpak` files can be mounted and used directly
- Modular animated sprites built in SpriteFoundry can be loaded into `AnimatedSprite` or a planned `ModularSprite` class
- Supports future Dexium features like player states, animation graphs, and character controllers

---

## 📁 Repository

🌐 [SpriteFoundry GitHub Repo](https://github.com/Dextron12/SpriteFoundry)  
🕹 Paired with: [Dexium 2D](https://github.com/Dextron12/Dexium2D)

---

## ❤️ Special Thanks

This tool was built for solo game devs and pixel artists who want full control over how their characters move, animate, and look in-game. Inspired by tools like Spine, aseprite, and Unity’s animation rigging.

---

> Have a feature request or idea? Open an issue or ping me on the Dexium repo!
