# OBS Template Manager — Architecture

Target: OBS Studio on Windows 10/11 x64. Native OBS frontend plugin in C++/Qt.

## Modules
- Plugin dock: online library, local ZIP import, export, install and restore UI.
- Catalog: HTTPS manifest and GitHub Release assets.
- Package: versioned manifest, scene collection JSON and assets.
- Installer: transactional staging, validation, path rewriting, collision-safe names.
- Backup: timestamped copy of affected OBS configuration before modification.
- Device mapper: user chooses local video/audio devices after import.

## Safety rules
- Never overwrite existing collections or scenes without explicit user approval.
- Default to installing a new collection.
- Merge requires remapping source identifiers, names, scene references, filters and transitions.
- No secrets (stream keys, credentials) in exports.
- Reject ZIP path traversal and oversized/untrusted archives.
- Verify package hashes and preserve rollback data.
- Avoid editing active OBS configuration files directly; use supported frontend APIs where feasible.
- Backup/restore behavior and compatibility must be tested against actual OBS versions.

## Status
Design specification only. Native plugin, installers and integration tests have not yet been implemented.
