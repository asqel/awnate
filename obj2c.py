import json

def parse_obj(file_path):
    """Parse un fichier .obj pour extraire les sommets et arêtes."""
    vertices = []
    edges = set()  # Utiliser un set pour éviter les doublons

    with open(file_path, "r") as f:
        for line in f:
            parts = line.strip().split()
            if not parts:
                continue

            if parts[0] == "v":  # Ligne de sommet
                vertices.append(tuple(map(float, parts[1:4])))

            elif parts[0] == "f":  # Ligne de face
                # Les indices dans les fichiers OBJ commencent à 1
                indices = [int(p.split('/')[0]) - 1 for p in parts[1:]]
                for i in range(len(indices)):
                    # Ajouter les arêtes pour chaque paire de sommets connectés
                    edge = tuple(sorted((indices[i], indices[(i + 1) % len(indices)])))
                    edges.add(edge)

    return vertices, list(edges)

def obj_to_json(obj_file) -> tuple[tuple[int, int, int], list[int, int]]:
    """Convertit un fichier .obj en un fichier JSON."""
    vertices, edges = parse_obj(obj_file)
    return (vertices, edges)


def read_model_from_file(file_path):
    """Lit un modèle 3D à partir d'un fichier JSON."""
    with open(file_path, "r") as f:
        return json.load(f)

def convert_to_mesh3d(vertices, edges):
    """Convertit les données du modèle en une structure mesh3d_t."""
    # Génère les chaînes C pour les sommets
    vertices_str = ",\n    ".join(
        [f"{{{v[0]:.6f}, {v[1]:.6f}, {v[2]:.6f}}}" for v in vertices]
    )
    vertices_block = f"vec3_t vertices[] = {{\n    {vertices_str}\n}};"

    # Génère les chaînes C pour les arêtes
    edges_str = ",\n    ".join(
        [f"{{{e[0]}, {e[1]}}}" for e in edges]
    )
    edges_block = f"u32_pair_t edges[] = {{\n    {edges_str}\n}};"

    # Génère la structure mesh3d_t
    mesh3d = f"""\
#include "geometry.h"

{vertices_block}

{edges_block}

mesh3d_t mesh = {{
    .vertices = vertices,
    .edges = edges,
    .vertices_len = {len(vertices)},
    .edges_len = {len(edges)},
}};
"""
    return mesh3d


mod = obj_to_json("Car.obj")

mesh3d = convert_to_mesh3d(mod[0], mod[1])
with open("mesh3d.c", "w") as f:
	f.write(mesh3d)