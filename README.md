# IOT102 G2 — Fire Detection and Warning System

This repository contains the firmware, final report, project documentation, and supporting references for the IOT102 Group 2 project.

## Directory structure

| Path | Purpose |
|---|---|
| `src/` | ESP32/Arduino firmware (the implementation source of truth) |
| `reports/overleaf/` | Self-contained Overleaf report package |
| `reports/final/` | Exported final PDF |
| `reports/markdown/` | Current Markdown report source |
| `docs/ai-audit/` | AI declarations, guideline, and individual audit logs |
| `docs/design/` | Editable system diagram and full-resolution diagram exports |
| `docs/project/` | Project plan and handover documentation |
| `knowledge/` | Project analysis, requirements, architecture, progress, and issue notes |
| `references/` | Course templates and research/reference material |
| `archive/` | Superseded drafts retained for traceability |

## Primary files

- Firmware: `src/FireDetectionSingleFinal.ino`
- Overleaf source: `reports/overleaf/main.tex`
- Final report: `reports/final/IOT102_G2_IoT-Based_Fire_Detection_and_Warning_System_Final_Report.pdf`
- Current Markdown report: `reports/markdown/freport.md`
- Report review notes: `reports/REPORT_REVIEW.md`

## Notes

- `reports/overleaf/` intentionally contains its own image copies so the folder can be uploaded and compiled independently.
- `archive/` is not part of the current deliverable. It is retained because this workspace does not currently have usable Git history for recovering removed files.
- The hidden `.agents/`, `.aws/`, `.codex/`, and `.git/` directories are environment metadata and were not modified.
