# UE5 Custom RDG Volumetric Fog & Environment Control System

Unreal Engine 5のRDG（Render Dependency Graph）を用いたボリュメトリックフォグ/クラウドシェーダーと、C++・UMGによるリアルタイム環境操作UIを統合したグラフィックスデモプロジェクトです。

---

## 目次 (Table of Contents)

- [プロジェクト概要](#プロジェクト概要)
- [主な機能 \& 技術的ハイライト](#主な機能--技術的ハイライト)
- [システム構成・技術要素](#システム構成技術要素)
- [使い方 (Usage)](#使い方-usage)
  - [動作環境](#動作環境)
  - [実行方法 (パッケージ版)](#実行方法-パッケージ版)
  - [エディタでの導入・ビルド手順](#エディタでの導入ビルド手順)
- [ディレクトリ構成](#ディレクトリ構成)
- [注意事項・ライセンス](#注意事項ライセンス)

---

## プロジェクト概要

本プロジェクトは、UE5の標準ボリュメトリック機能に依存せず、**カスタムHLSLおよびRDG（Render Dependency Graph）を用いて独自にレイマーチング（Ray Marching）およびライティング計算を実装したボリュメトリッククラウド/フォグシステム**です。

レイマーチングによる密度サンプリング、3Dノイズ（Perlin / Worley Noise）を用いた形状生成、ならびにBeer-Lambertの法則に基づく光の減衰計算をすべて自前のシェーダーコードで算出しています。
さらに、この独自シェーダーのパラメータを C++ アクター（`AVolumetricCloudManager`）および Material Parameter Collection (MPC) を介して制御し、パッケージ実行環境下でユーザーが画面上のUIスライダーからリアルタイムに環境操作（時刻・風速・雲量）できる統合アーキテクチャを構築しました。

---

## 主な機能 & 技術的ハイライト

- **自作レイマーチング・シェーダー (Custom Ray Marching)**:
  - カメラ視点からのレイキャスティングとレイステップ毎の密度サンプリングアルゴリズムを自前で計算。
  - 3Dノイズ合成（Worley / Perlin Noise）によるリアルな雲の立体形状・細部のディテール生成。
- **物理ベースのライティング計算 (Volumetric Lighting)**:
  - **Beer-Lambertの法則**に基づくレイステップ毎の光の透過・減衰計算。
  - 太陽光の異方性散乱（Phase Function / Henyey-Greenstein関数）による逆光・順光表現の自作実装。
- **動的ライティング＆時刻連動 (Time of Day)**:
  - 0:00〜24:00の時刻変化に応じて、自作シェーダーへ渡す太陽方向ベクトルおよび放射照度（Irradiance）を補間更新（`HH:MM` デジタル表記対応）。
- **C++ / RDG / UMG リアルタイム連携アーキテクチャ**:
  - UIスライダーの操作結果を C++（`AVolumetricCloudManager`）が受け取り、MPC経由で自作シェーダーへ即時伝達・再描画する低遅延な制御設計。

---

## システム構成・技術要素

- **Shader / Graphics Pipeline**: 
  - **Custom HLSL / RDG (Render Dependency Graph)**
  - Ray Marching Algorithm
  - 3D Worley & Perlin Noise Generator
  - Beer-Lambert Law & Henyey-Greenstein Phase Function
- **Engine / Architecture**:
  - Unreal Engine 5.x (C++ Project)
  - Material Parameter Collection (MPC)
  - UMG (Widget Blueprint / C++ Binding)

---

## 使い方 (Usage)

### 動作環境
- **OS**: Windows 10 / 11 (64-bit)
- **GPU**: DirectX 12 対応グラフィックボード

### 実行方法 (パッケージ版)
1. リポジトリ右側の **[Releases]** ページから最新の `VolumetricFog_Windows_Build.zip` をダウンロードします。
2. ダウンロードした ZIP ファイルを解凍します。
3. フォルダ内の `VolumetricFog.exe` を実行すると、デモが起動します。

### エディタでの導入・ビルド手順
1. 本リポジトリをクローンします：
   ```bash
   git clone https://github.com/atushi3110/UE5-CustomRDG-VolumetricFog.git
2. UE5-CustomRDG-VolumetricFog.uproject を右クリックし、Generate Visual Studio project files を実行します。
3. 生成された .sln ファイルを Visual Studio 2022 で開き、Development Editor 構成でビルドします。
4. Unreal Editor を起動し、メインレベルを開いて Play または Platforms > Package Project を実行します。
---

## ディレクトリ構成

<details>
<summary>テキスト形式のディレクトリ一覧を表示</summary>

```text
UE5-CustomRDG-VolumetricFog/
├── Config/                      # プロジェクトおよびプラットフォーム設定ファイル
├── Content/                     # プロジェクトのアセットフォルダ
│   ├── Environment/             # マテリアル、MPC、カラーカーブ等
│   ├── Shaders/                 # カスタムHLSL / RDGシェーダー関連コード
│   └── UI/                      # WBP_FogController (UMGウィジェット)
├── Source/                      # C++ ソースコード
│   └── VolumetricFog/
│       ├── VolumetricCloudManager.h   # 環境統括C++アクター (MPC/時刻制御)
│       └── VolumetricCloudManager.cpp
├── build/                       # パッケージ出力先 (Windowsビルド成果物 / .gitignore対象)
├── README.md                    # 本ドキュメント
└── UE5-CustomRDG-VolumetricFog.uproject
```

</details>

```mermaid
graph TD
    classDef root fill:#2b3137,stroke:#fff,stroke-width:2px,color:#fff;
    classDef cpp fill:#1f6feb,stroke:#388bfd,stroke-width:1px,color:#fff;
    classDef shader fill:#8957e5,stroke:#a371f7,stroke-width:1px,color:#fff;
    classDef content fill:#238636,stroke:#2ea043,stroke-width:1px,color:#fff;

    Root["UE5-CustomRDG-VolumetricFog/"]:::root

    subgraph SourcePackage["Source/ (C++ Logic)"]
        Manager["VolumetricCloudManager<br/>(.h / .cpp)"]:::cpp
    end

    subgraph ContentPackage["Content/ (Assets & Shaders)"]
        subgraph Shaders["Shaders/"]
            HLSL["Custom HLSL / RDG Code"]:::shader
        end
        subgraph Environment["Environment/"]
            MPC["Material Parameter Collection (MPC)"]:::content
            Mat["Materials & Textures"]:::content
        end
        subgraph UI["UI/"]
            WBP["WBP_FogController (UMG)"]:::content
        end
    end

    Root --> SourcePackage
    Root --> ContentPackage

    WBP -. "UI操作イベント" .-> Manager
    Manager -. "パラメータ一括更新" .-> MPC
    MPC -. "定数バッファ同期" .-> HLSL
```
    
---

## 注意事項・ライセンス

### 注意事項 (Disclaimer)
本プロジェクトはポートフォリオおよび技術検証を目的として作成されています。
配布している実行ファイルやお使いの環境での動作保証はいたしかねますのでご了承ください。

### ライセンス (License)
本プロジェクトのソースコードおよびアセットは MIT License のもとで公開されています。商用・非商用を問わず自由にご利用いただけます。