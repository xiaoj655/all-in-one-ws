<script setup>

</script>

<template>
  <main @click="this.$store.commit('increment')">
    {{ this.$store.state.count }}
  </main>
</template>

<style scoped></style>
