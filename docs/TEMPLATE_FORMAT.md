# Proposed template ZIP format

- `manifest.json`: template id, name, version, compatibility, asset checksums
- `scenes/collection.json`: OBS scene collection export
- `assets/`: bundled images, audio, video and animations
- `preview/`: thumbnail and optional preview clip

Importer must validate archive paths, size, schema and checksums; install media to a stable directory; rewrite media paths; and preserve existing collections. Capture devices and third-party plugins require local mapping or installation. Never export streaming credentials.
